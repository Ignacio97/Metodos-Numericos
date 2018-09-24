#include <stdio.h>
#include <stdlib.h>

#define flush() setbuf(stdin,NULL);
#define CLEAR() system("clear"); //Linux & mac
//#define CLEAR() system("cls"); //Windows

/***INICIA PROTOTIPOS****/
void imprimeMatriz(float **matriz, int ren);
float** generaMatriz(int size);
void llenaMatriz(float **matriz, int size) ;
void gaussJordan(int size);
/***TERMINA PROTOTIPOS****/

/****INICIA MAIN****/
int main(int argc, char const *argv[]) {

  if (argc!=2) {
    printf("Error, an argument is expected.Example:\n" );
    printf("p6.exe n : n= unknown variables number \n");
  }
  else{
    gaussJordan(atoi(argv[1]));
  }


  return EXIT_SUCCESS;
}
/****TERMINA MAIN****/

  /****  INICIO FUNCIONES****/

  //Fun que imprime una matriz cuadrada de n tamaño.
  void imprimeMatriz(float **matriz, int ren) {
      int i,j,col=ren;

      printf("\n");
    for (i = 0; i < ren; i++) {
      for (j = 0; j < col+1; j++) {
        printf("%.2f\t",matriz[i][j]);
      }
      printf("\n");
    }
  }

  //Fun que genera una matriz cuadrada, recibe como parametro el tramaño de la matriz a crear. Devuelve un doble apuntador a la matriz.
  float** generaMatriz(int size) {
      float **matriz=NULL;
      int i;

      matriz=(float**)calloc(size,sizeof(float*)); //Asignacion de renglones.

      if (!matriz) {
        printf("\nERROR! No se pudo reservar memoria!\n");
      }
      else{
        for ( i = 0; i < size; i++)
          matriz[i]=(float*)calloc(size+1,sizeof(float)); //Asignacion de columatriznas.
      }

      return matriz;
  }

  //Fun que llena la matriz con los datos que ingresa el usuario.
  void llenaMatriz(float **matriz, int size) {
        int i,j;
    for ( i = 0; i < size; i++) {
      printf("Ren %d:\n",i+1 );

      for ( j = 0; j < size+1; j++) {
        fseek(stdin,j,SEEK_SET); //Permite capturar los datos por renglones.
        flush();
        scanf("%f",&matriz[i][j]);
      }
    }
  }

  //Fun equivalente al metodo de gaussJordan.
  void gaussJordan(int size) {
    int i,j,k;
    float **m=NULL,*resultado=NULL,c=0;

    //Asignacion de memoria.
    m=generaMatriz(size);
    resultado=(float*)calloc(size,sizeof(float));


    llenaMatriz(m,size);

    for(j=0; j<size; j++){
        for(i=0; i<size; i++){
            if(i!=j){
                c=m[i][j]/m[j][j];
                for(k=0; k<=size; k++){
                    m[i][k]=m[i][k]-c*m[j][k];
                }
            }
        }
    }



    for ( i = 0; i < size; i++) {
      c=m[i][i];
        for ( j = 0; j <=size; j++) {
          if(m[i][j]!=0)
            m[i][j]=m[i][j]/c;
        }
        resultado[i]=m[i][size];
        printf("\n x%d=%f\n",(i+1),resultado[i]);
    }

imprimeMatriz(m,size);


//solucion alterna pero menos optima

    //Imprime la solucion del sistema.
  /*  printf("\nSolucion:\n");
    for(i=0; i<size; i++){
        resultado[i]=(m[i][size])/(m[i][i]);
        printf("\n x%d=%f\n",(i+1),resultado[i]);
    }*/



    //liberacion de memoria.
    free(resultado);
    free(m);
}

/****  FIN FUNCIONES****/

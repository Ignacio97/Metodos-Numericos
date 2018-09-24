#include <stdio.h>
#include <stdlib.h>

#define display(a) for ( int i = 0; i <=a; i++) { i==a? printf("\n"):printf("X%d\t\t",i+1);}
#define flush() setbuf(stdin,NULL);
#define CLEAR() system("clear"); //Linux & mac
//#define CLEAR() system("cls"); //Windows

/***INICIA PROTOTIPOS****/
void imprimeMatriz(float **matriz, int ren);
float** generaMatriz(int size);
void llenaMatriz(float **matriz, int size) ;
void llenaResultados(float *array,int size) ;
void gaussSeidel(int size,int ite);
/***TERMINA PROTOTIPOS****/


/***INICIA MAIN***/
int main(int argc, char const *argv[]) {


  if (argc!=3) {
    printf("Error, two arguments are expected.Example:\n" );
    printf("p5.exe n imax : n= unknown variables number : imax= max iterations number\n");
  }
  else{
    gaussSeidel(atoi(argv[1]),atoi(argv[2]));
  }


  return EXIT_SUCCESS;
}
/***TERMINA MAIN**/

/****  INICIO FUNCIONES****/
  void imprimeMatriz(float **matriz, int ren) {
      int i,j,col=ren;
      printf("\n");
    for (i = 0; i < ren; i++) {
      for (j = 0; j <=col; j++) {
        printf("%.2f\t",matriz[i][j]);
      }
      printf("\n");
    }
  }

  float** generaMatriz(int size) {
      float **matriz=NULL;
      int i;

      matriz=(float**)calloc(size,sizeof(float*)); //Asignacion de renglones.

      if (!matriz) {
        printf("\nERROR! No se pudo reservar memoria!\n");
      }
      else{
        for ( i = 0; i < size; i++)
          matriz[i]=(float*)calloc(size+1,sizeof(float)); //Asignacion de columnas.
      }

      return matriz;
  }

  void llenaMatriz(float **matriz, int size) {
        int i,j;
    for ( i = 0; i < size; i++) {
      printf("Ren %d:\n",i+1 );

      for ( j = 0; j <=size; j++) {
        fseek(stdin,j,SEEK_SET);
        flush();
        scanf("%f",&matriz[i][j]);
      }
    }

  }




  void gaussSeidel(int size,int ite) {
    float **matriz=NULL,*respuestas,aux=0;
    int i,j,k;

    //Asiganciones de memoria.
    respuestas=(float*)calloc(size,sizeof(float));

    matriz=generaMatriz(size);

    llenaMatriz(matriz,size);
    display(size);

//Ejecutarse si calloc no llegara a funcionar.
  /*  for ( i = 0; i < size; i++) {
      respuestas[i]=0;

    }*/


    for(i=0; i<ite; i++){
        for(j=0; j<size; j++){
            respuestas[j]=matriz[j][size];
            for(k=0; k<size; k++){
                if(j!=k){
                    respuestas[j]-=matriz[j][k]*respuestas[k];
                }
            }
            respuestas[j]/=matriz[j][j];
            printf("%.7f\t",respuestas[j]);
        }
      printf("\n");
    }
    imprimeMatriz(matriz,size);
  free(matriz);
  free(respuestas);
  }

/****  FIN FUNCIONES****/

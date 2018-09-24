#include <stdio.h>
#include <stdlib.h>

#define flush() setbuf(stdin,NULL);
#define CLEAR() system("clear"); //Linux & mac
//#define CLEAR() system("cls"); //Windows

/***INICIA PROTOTIPOS****/
void imprimeMatriz(double **matriz, int ren);
double** generaMatriz(int size);
void llenaMatriz(double **matriz, int size) ;
void llenaDiagonal(double **m,int size);
void llenaResultados(double *array,int size) ;
void inversa(int size);
/***TERMINA PROTOTIPOS****/


/***INICIA MAIN***/
int main(int argc, char const *argv[]) {

  if (argc!=2) {
    printf("Error, an argument is expected.Example:\n" );
    printf("p5.exe n : n= unknown variables number \n");
  }
  else{
    inversa(atoi(argv[1]));
  }


  return EXIT_SUCCESS;
}
/***TERMINA MAIN**/

/****  INICIO FUNCIONES****/
  void imprimeMatriz(double **matriz, int ren) {
      int i,j,col=ren;
      printf("\n");
    for (i = 0; i < ren; i++) {
      for (j = 0; j < col*2; j++) {
        printf("%.2f\t",matriz[i][j]);
        if (j==ren-1) {
            printf("|\t");
        }
      }
      printf("\n");
    }
  }

  double** generaMatriz(int size) {
      double **matriz=NULL;
      int i;

      matriz=(double**)calloc(size,sizeof(double*)); //Asignacion de renglones.

      if (!matriz) {
        printf("\nERROR! No se pudo reservar memoria!\n");
      }
      else{
        for ( i = 0; i < size; i++)
          matriz[i]=(double*)calloc(size*2,sizeof(double)); //Asignacion de columnas.
      }

      return matriz;
  }

  void llenaMatriz(double **matriz, int size) {
        int i,j;
    for ( i = 0; i < size; i++) {
      printf("Ren %d:\n",i+1 );

      for ( j = 0; j < size; j++) {
        fseek(stdin,j,SEEK_SET);
        flush();
        scanf("%lf",&matriz[i][j]);
      }
    }
    llenaDiagonal(matriz,size);//llena de unos la matriz equivalente.
  }

  void llenaDiagonal(double **m,int size){
    int i,j;

    for ( i = 0; i < size; i++) {
      for ( j = size; j < size*2; j++) {
          if (i+size==j) {
            m[i][j]=1;
          }
      }
    }
  }

  void llenaResultados(double *array,int size) {
    int i;

    printf("\nCapture resultados:");
    for ( i = 0; i < size; i++) {
      fseek(stdin,i,SEEK_SET);
      flush();
      scanf("%lf",&array[i]);
    }
  }

  void inversa(int size) {
    double **matriz=NULL,*resultado=NULL,c=0,*solucion=NULL;
    int i,j,k;

    solucion=(double*)calloc(size,sizeof(double));
    resultado=(double*)calloc(size,sizeof(double));
    matriz=generaMatriz(size);

    llenaMatriz(matriz,size);
    llenaResultados(resultado,size);

    for(j=0; j<size; j++){
        for(i=0; i<size; i++){
            if(i!=j){
                c=matriz[i][j]/matriz[j][j];
                for(k=0; k<size*2; k++){
                    matriz[i][k]=matriz[i][k]-c*matriz[j][k];
                }
            }
        }
    }


    for ( i = 0; i < size; i++) {
      c=matriz[i][i];
        for ( j = 0; j<size*2; j++) {
          if(matriz[i][j]!=0)
            matriz[i][j]=matriz[i][j]/c;
        }

    }

    for ( i = 0; i < size; i++) {

        for ( j = size; j<size*2; j++) {
        solucion[i]+=matriz[i][j]*resultado[j-size];
        }
        printf("\n x%d=%f\n",(i+1),solucion[i]);
    }


    imprimeMatriz(matriz,size);

    free(matriz);
	  free(solucion);
	  free(resultado);

  }
/****  FIN FUNCIONES****/

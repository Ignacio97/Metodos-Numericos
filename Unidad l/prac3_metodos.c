#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//macro equivalente a la ecuacion 2x^3-11.7x^2+17.7x-5
#define fun(value) 2*pow(value,3)-11.7*pow(value,2)+17.7*value-5
#define derivada(value) 6*pow(value,2)-23.4*value+17.7

/***PROTOTIPOS DE FUNCION****/
double evalua_Fun(double xi);
double evalua_derivada(double xi);
double fun_xi(double valor );
double error_abs(double Xs_act,double Xs_old);
void imprime(double xi,double fxi, double dfxi,double ea,int ite);
double primer_orden(double xi,double es,int iteraciones);
/****FIN PROTOTIPOS**/

/***INICIA MAIN***/
int main(int argc, char const *argv[]) {
  /*Usar como valores iniciales [0,3,4], ea < 0.10,0.01, 0.001*/

  double a=0;
  printf("con a= %f\n",a);
  printf("\nresultado %.10f\n\n",primer_orden(a,10,1000));
  printf("\nresultado %.10f\n\n",primer_orden(a,1,1000));
  printf("\nresultado %.10f\n\n",primer_orden(a,0.001,1000));
  printf("\nresultado %.10f\n\n",primer_orden(a,0,1000));

  return EXIT_SUCCESS;
}
/***TERMINA MAIN***/

/*****INICIO DE FUNCIONES***/
//Fun que evalua la ecuacion en xi.
double evalua_Fun(double xi){
  return (double) fun(xi);
}
//Fun. que evalua la ecuacion derivada en xi.
double evalua_derivada(double xi){
  return (double) derivada(xi);
}
//Fun. que calcula el valor de xi
double fun_xi(double valor ){

  return (double) valor - (evalua_Fun(valor)/evalua_derivada(valor));
}
//Fun. que calcula el error absoluto.
double error_abs(double Xs_act,double Xs_old){
	 return (double) fabs((1- (Xs_old/Xs_act))*100);
}
//Fun. que imprime las iteraciones.
void imprime(double xi,double fxi, double dfxi,double ea,int ite){
  if (ite==1) {
    printf("ite\t\txi\t\tf(xi)\t\tf'(xi)\t\tea\n");
  }
printf("%d\t%.10f\t%.10f\t%.10f\t%.10f\n",ite,xi,fxi,dfxi,ea);

}
//Fun. equivale al metodo Newton Raphson de primer orden.
double primer_orden(double xi,double es,int iteraciones){
  double fxi=0,dfx=0,xi_old=0,ea=0;
  int ite=0;


  do {
      ite++;
    fxi=evalua_Fun(xi);
    dfx=evalua_derivada(xi);


      if(xi!=0 && ite>1){
        ea=error_abs(xi,xi_old);
      }
      else{ea=100;}

    imprime(xi,fxi,dfx,ea,ite);
    xi_old=xi;
    xi=fun_xi(xi);


      if(fxi==0)
        break;

       if(ea<es)
          if(ite>1)
            break;

  } while(ite<iteraciones);

return xi;
}
/*****FIN DE FUNCIONES***/

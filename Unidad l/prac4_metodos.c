#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//macro equivalente a la ecuacion cos(x)-3x+5 y sus derivadas.
#define fun(value) cos(value)-3*value+5
#define derivada(value) -sin(value)-3
#define derivada2(value) -cos(value)

/***PROTOTIPOS DE FUNCION****/
double evalua_Fun(double xi);
double evalua_derivada(double xi);
double evalua_derivada2(double xi);
double fun_xi(double valor );
double error_abs(double Xs_act,double Xs_old);
void imprime(double xi,double fxi, double dfxi,double dfxii,double ea,int ite);
double segundo_orden(double xi,double es,int iteraciones);
/****FIN PROTOTIPOS**/

/***INICIA MAIN***/
int main(int argc, char const *argv[]) {

  printf("\nresultado %.10f\n\n",segundo_orden(3.141592/2,0.001,1000));

  return EXIT_SUCCESS;
}
/***TERMINA MAIN***/

/*****INICIO DE FUNCIONES***/
//Fun que evalua la ecuacion en xi.
double evalua_Fun(double xi){
  return (double) fun(xi);
}
//Fun. que evalua la derivada en xi.
double evalua_derivada(double xi){
  return (double) derivada(xi);
}
//Fun. que evalua la 2da derivada en xi.
double evalua_derivada2(double xi){
  return (double) derivada2(xi);
}
//Fun. que calcula el valor de xi
double fun_xi(double valor ){

  return (double) valor - (evalua_Fun(valor)*evalua_derivada(valor))/(pow(derivada(valor),2)-evalua_Fun(valor)*evalua_derivada2(valor));
}
//Fun. que calcula el error absoluto.
double error_abs(double Xs_act,double Xs_old){
	 return (double) fabs((1- (Xs_old/Xs_act))*100);
}
//Fun. que imprime las iteraciones.
void imprime(double xi,double fxi, double dfxi,double dfxii,double ea,int ite){
  if (ite==1) {
    printf("ite\t\txi\t\tf(xi)\t\tf'(xi)\t\tf''(xi)\t\tea\n");
  }
printf("%d\t%.10f\t%.10f\t%.10f\t%.10f\t%.10f\n",ite,xi,fxi,dfxi,dfxii,ea);

}
//Fun. equivale al metodo Newton Raphson de segundo orden.
double segundo_orden(double xi,double es,int iteraciones){
  double fxi=0,dfx=0,xi_old=0,ea=0,dfx2=0;
  int ite=0;


  do {
      ite++;
    fxi=evalua_Fun(xi);
    dfx=evalua_derivada(xi);
    dfx2=evalua_derivada2(xi);

      if(xi!=0 ){
        ea=error_abs(xi,xi_old);
      }
      else{ea=100;}

    imprime(xi,fxi,dfx,dfx2,ea,ite);
    xi_old=xi;
    xi=fun_xi(xi);

       if(ea<es)
          if(ite>1)
            break;

  } while(ite<iteraciones);

return xi;
}
/*****FIN DE FUNCIONES***/

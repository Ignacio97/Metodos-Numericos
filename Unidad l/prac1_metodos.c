#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//macro equivalente a la ecuacion x^2-4x-8.98
//#define fun(value) pow(value,2)-4*value -8.98
#define fun(value) pow(value,3)+4*pow(value,2) -10


/****PROTOTIPOS DE FUNCION ****/
double error_abs(double Xs_act,double Xs_old);
double fun_XS(double a, double b);
double evaluaEn_Xs(double Xs);
double	evaluaEn_a(double a);
double evaluaEn_b(double a);
double metodo_Biseccions(double a,double b,double es,int iMax);
/***FIN PROTOTIPOS ***/

/***INICIA MAIN****/
int main(int argc, char const *argv[]){

	/**Intervalos a evaluar a Evaluar
	[2,3],[-1,6],[1,3],[-6,-3],[10,20]**/

	printf("\nresultado %f\n\n",metodo_Biseccions(-2,1,10,200));

	return EXIT_SUCCESS;
}
/*****TERMINA MAIN****/

/*** INICIO DE FUNCIONES ***/

//Fun. que devuelve el error absoluto.
double error_abs(double Xs_act,double Xs_old){

	return (double) fabs((1- (Xs_old/Xs_act))*100);
}

//Fun. que calcula Xs.
double fun_XS(double a, double b){

	return (double) (a+b)/2;
}

//Fun. que evalua la ecuacion en Xs.
double evaluaEn_Xs(double Xs){

    return (double) fun(Xs);
}

//Fun. que evalua la ecuacion en a.
double evaluaEn_a(double a){
    return  (double) fun(a);
}

//Fun. que evalua la ecuacion en b.
double evaluaEn_b(double b){
    return  (double) fun(b);
}

//Fun. que imprime las iteraciones.
void imprime(double a,double b, double xs, double fa, double fxs, double err, int ite){
if(ite==1)
printf("a\t\tb\t\txs\t\tfa\t\tfxs\t\terr\n");

printf("%f\t%f\t%f\t%f\t%f\t%f\n",a,b,xs,fa,fxs,err );

}

//Fun. equivalente al metodo de biseccion.
double metodo_Biseccions(double a,double b,double es,int iMax){
int ite=0;
double test=0,ea=0,fa=0,fxs=0,xs=0,xs_ant=0,b_old,a_old;



if((evaluaEn_a(a)*evaluaEn_b(b))<0){

	do{

			ite++;					//contador
			xs=fun_XS(a,b);
			fa= evaluaEn_a(a);
			fxs=evaluaEn_Xs(xs);

			if (xs!=0 && ite>1)
				ea=(double)fabs(error_abs(xs,xs_ant));

				xs_ant=xs;
				test= evaluaEn_a(a) * evaluaEn_Xs(xs);
				a_old=a;
				b_old=b;

				if (test<0)
					b=xs;
				else if(test>0)
					a=xs;
				else
					ea=0;


					imprime(a_old,b_old,xs,fa,fxs,ea,ite);

			if(ea<es)
				if(ite>1)
					break;

	}while(ite<iMax);
}

	else
		printf("%s","Error,f(a)*f(b) es mayor a 0 ");

return  xs;
}
/*** FIN DE FUNCIONES ***/

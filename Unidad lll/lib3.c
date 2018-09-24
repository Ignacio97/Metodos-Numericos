#include <stdio.h>
#include <math.h>
#include "lib3.h"




float fun1 (float x){

  return 0.2 + (25*x) - (200*x*x) + (675*x*x*x) - (900*x*x*x*x) + (400*x*x*x*x*x);
}

float fun2 (float x){

  return exp(x);
}

float fun3 (float x){

  return 1/(1+x*x);
}

float fun4 (float x){

  return log10(x);
}



void trapecio(float a, float b, float (*fun)(float x)){
    float res=0;

    res =  (fun(a)+fun(b)) / 2;
    res = res* (b-a);

 printf("El resultado es %f\n",res );
}


void menu_ecuaciones(/* arguments */) {
  printf("[1] 0.2+.....400x^5\n" );
  printf("[2] e^x\n" );
  printf("[3] 1/1+x^2\n" );
  printf("[4] log10 x\n" );
}


void menu() {
  int opc;

do{
  printf("[1] trapecio simple\n" );
  printf("[2] trapecio multiple\n" );
  printf("[0] salir\n" );
  printf("Seleccione una opcion:" );
  setbuf(stdin,NULL);
  scanf("%d",&opc );

switch (opc) {

  case 1:
  printf("\n\tMetodo Trapecio Simple\n\n" );
    menutrapecio();
    break;

  case 2:
  printf("\n\tMetodo Trapecio Multiple\n\n" );
    menutrapecio_multiple();
    break;

  case 0:
    printf("Saliendo...\n");
    break;

  default :
    printf("opcion no valida.\n" );
    break;
}

}while(opc!=0);


}

void menutrapecio() {
  float a,b;
  int opc;

    menu_ecuaciones();
    scanf("%d",&opc);

    switch (opc) {


  case 1:
  printf("Ingrese a:" );
  scanf("%f",&a);
  printf("Ingrese b:" );
  scanf("%f",&b);
  trapecio(a,b,fun1);
    break;

  case 2:
  printf("Ingrese a:" );
  scanf("%f",&a);
  printf("Ingrese b:" );
  scanf("%f",&b);
  trapecio(a,b,fun3);
  break;

  case 3:
  printf("Ingrese a:" );
  scanf("%f",&a);
  printf("Ingrese b:" );
  scanf("%f",&b);
  trapecio(a,b,fun3);
  break;
  case 4:
  printf("Ingrese a:" );
  scanf("%f",&a);
  printf("Ingrese b:" );
  scanf("%f",&b);
  trapecio(a,b,fun4);
  break;
  }
}

void trapecioMultiple(float a,float b,int n,float (*fun)(float x) ) {

  float h=0,res=0,sumatoria=0;
  float i=0;
  int j;

  h=(b-a)/n;
  printf("f(%f)=%f\n",a,fun(a));

  i+=h+a;
  for ( j =0; j < n-1; j++ ) {
    printf("f(%f)=%f\n",i,fun(i));
    sumatoria+=fun(i);
    i+=h;
  }
printf("f(%f)=%f\n",i,fun(i));
  printf("sumatoria:%f\n",sumatoria );
  res=fun(a)+(2*sumatoria)+fun(b);
  res=res/(2*n);
  res = res*(b-a);
  printf("El resultado es %f\n",res );
}


void menutrapecio_multiple() {
  float a,b;
  int opc,n;

    menu_ecuaciones();
    scanf("%d",&opc);

    switch (opc) {


  case 1:
  printf("Ingrese a:" );
  scanf("%f",&a);
  printf("Ingrese b:" );
  scanf("%f",&b);
  printf("Ingrese segmentos:" );
  scanf("%d",&n);
  trapecioMultiple(a,b,n,fun1);
    break;

  case 2:
  printf("Ingrese a:" );
  scanf("%f",&a);
  printf("Ingrese b:" );
  scanf("%f",&b);
  printf("Ingrese segmentos:" );
  scanf("%d",&n);
  trapecioMultiple(a,b,n,fun2);
  break;

  case 3:
  printf("Ingrese a:" );
  scanf("%f",&a);
  printf("Ingrese b:" );
  scanf("%f",&b);
  printf("Ingrese segmentos:" );
  scanf("%d",&n);
  trapecioMultiple(a,b,n,fun3);
  break;

  case 4:
  printf("Ingrese a:" );
  scanf("%f",&a);
  printf("Ingrese b:" );
  scanf("%f",&b);
  printf("Ingrese segmentos:" );
  scanf("%d",&n);
  trapecioMultiple(a,b,n,fun4);
  break;
  }

}

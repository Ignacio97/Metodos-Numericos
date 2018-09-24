#include <stdio.h>
#include <math.h>
#include "lib4.h"


float fun1(float x,float y){ return -x*y*y;}
float fun2(float x,float y) {return x+y;}
float fun3(float x,float y){ return 1-x+4*y;}
float fun4(float x,float y){ return y-x*x+1;}
float fun5(float x,float y){ return x+y*y;}
float fun6(float x,float y){ return 2*x*y;}


void runge(float a, float b, float h,float y0,float (*ecuacion) (float x,float y)){
  float k,k2,k3,k4;
  int i,paso=(int)((b-a)/h);


printf("k1\t\tk2\t\tk3\t\tk4\t\ty0\n" );
   for ( i=0 ;  i <= paso;a+=h,i++) {

     k=h*ecuacion(a,y0);
     k2=h*ecuacion(a+(h/2),y0+(.5*k));
     k3=h*ecuacion(a+(h/2),y0+(.5*k2));
     k4=h*ecuacion(a+h,y0+k3);

     y0=y0+(((float)1/(float)6)*( k + (2*k2) + (2*k3) + k4));

     printf("%f\t%f\t%f\t%f\t%f \n",k,k2,k3,k4,y0);
     }
}


void eulerMejorado(float a, float b, float h,float y0,float (*ecuacion) (float x,float y)) {
  int i,paso=(int)((b-a)/h);



   for ( i=0 ;  i <= paso;a+=h,i++) {

     y0=y0+((h/2)*(ecuacion(a,y0)+ecuacion(a+h,y0+(h*ecuacion(a,y0)))));

     printf("%.15fs\n",y0);
     }

}


void eulerr(float a, float b, float h,float y0,float (*ecuacion) (float x,float y)) {

 int i,paso=(int)((b-a)/h);

 //yn+1=yn+hf(xn,yn);
  for ( i=0 ;  i <= paso;a+=h, i++) {
    y0=y0+h*ecuacion(a,y0);
    printf("%f\n",y0 );

    }


}



//Fun. que despliega en pantalla el menu
void menu_ecuaciones(int i) {

if (i==0) {
  printf("[1] -xy^2\n" );
  printf("[2] x+y\n" );
  printf("[3] 1-x+4y\n" );
} else if (i==1) {
  printf("[1] y-x^2+1\n" );
  printf("[2] x+y^2\n" );
} else {
  printf("[1] 2xy\n" );
}


}

//Fun. donde se integran todos los metodos en forma de menu.
void menu() {
        int opc;

        do {
                printf("[1] Euler\n" );
                printf("[2] Euler mejorado\n" );
                printf("[3] runge kutta\n" );
                printf("[0] Salir\n" );
                setbuf(stdin,NULL);
                scanf("%d",&opc );

                switch (opc) {

                case 1:
                        printf("\n\tMetodo Euler\n\n" );
                        menuEuler();
                        break;

                case 2:
                        printf("\n\tMetodo Euler mejorado\n\n" );
                        menuEulerMejorado();
                        break;
                case 3:
                        printf("\n\tRunge...\n\n" );
                        menuRunge();
                        break;



                case 0:
                        printf("Saliendo...\n");
                        break;

                default:
                        printf("opcion no valida.\n" );
                        break;
                }

        } while(opc!=0);


}

void menuEuler() {
        float a,b,h,y;
        int opc;

        menu_ecuaciones(0);
        scanf("%d",&opc);

        switch (opc) {


        case 1:
                printf("Ingrese a:" );
                scanf("%f",&a);
                printf("Ingrese b:" );
                scanf("%f",&b);
                printf("Ingrese h:" );
                scanf("%f",&h);
                printf("Ingrese Y0:" );
                scanf("%f",&y);
                eulerr(a,b,h,y,fun1);
                break;

        case 2:
        printf("Ingrese a:" );
        scanf("%f",&a);
        printf("Ingrese b:" );
        scanf("%f",&b);
        printf("Ingrese h:" );
        scanf("%f",&h);
        printf("Ingrese Y0:" );
        scanf("%f",&y);
        eulerr(a,b,h,y,fun2);

                break;

        case 3:
        printf("Ingrese a:" );
        scanf("%f",&a);
        printf("Ingrese b:" );
        scanf("%f",&b);
        printf("Ingrese h:" );
        scanf("%f",&h);
        printf("Ingrese Y0:" );
        scanf("%f",&y);
        eulerr(a,b,h,y,fun3);

                break;
        default:
              printf("Opcion no valida!!\n" );
                break;
        }
}



void menuEulerMejorado() {
        float a,b,y,h;
        int opc;

        menu_ecuaciones(1);
        scanf("%d",&opc);

        switch (opc) {


        case 1:
        printf("Ingrese a:" );
        scanf("%f",&a);
        printf("Ingrese b:" );
        scanf("%f",&b);
        printf("Ingrese h:" );
        scanf("%f",&h);
        printf("Ingrese Y0:" );
        scanf("%f",&y);
eulerMejorado(a,b,h,y,fun4);
                break;

        case 2:
        printf("Ingrese a:" );
        scanf("%f",&a);
        printf("Ingrese b:" );
        scanf("%f",&b);
        printf("Ingrese h:" );
        scanf("%f",&h);
        printf("Ingrese Y0:" );
        scanf("%f",&y);
        eulerMejorado(a,b,h,y,fun5);
                break;



        default:
              printf("Opcion no valida\n" );
                break;
        }

}

void menuRunge() {
        float a,b,h,y;
        int opc;

        menu_ecuaciones(2);
        scanf("%d",&opc);

        switch (opc) {


        case 1:
        printf("Ingrese a:" );
        scanf("%f",&a);
        printf("Ingrese b:" );
        scanf("%f",&b);
        printf("Ingrese h:" );
        scanf("%f",&h);
        printf("Ingrese Y0:" );
        scanf("%f",&y);
                runge(a,b,h,y,fun6);
                break;

      default:
      printf("%s\n","opcion no valida" );
      break;
        }

}

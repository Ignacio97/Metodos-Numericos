#ifndef lib4
#define lib4

#define cls() system("clear"); //linux and mac
//#define cls() system("cls"); //Windows

float fun1 (float x,float y);
float fun2 (float x,float y);
float fun3 (float x,float y);
float fun4 (float x,float y);
float fun5 (float x,float y);
float fun6 (float x,float y);


void eulerr(float a, float b, float h,float y0,float (*ecuacion) (float x,float y));
void eulerMejorado(float a, float b, float h,float y0,float (*ecuacion) (float x,float y));
void runge(float a, float b, float h,float y0,float (*ecuacion) (float x,float y));

void menuEuler();
void menuEulerMejorado();
void menuRunge();
void menu();
void menu_ecuaciones(int i);


#endif

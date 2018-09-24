#ifndef lib3
#define lib3

#define cls() system("clear"); //linux and mac
//#define cls() system("cls"); //Windows

float fun1 (float x);
float fun2 (float x);
float fun3 (float x);
float fun4 (float x);


void trapecio(float a, float b, float (*fun)(float x));
void trapecioMultiple(float a,float b,int n,float (*fun)(float x) );
void simpson(float a, float b, float (*fun) (float x));
void simpsonMultiple(float a, float b,int n,float (*fun) (float x));
void simpsonTresOctavos(float a,float b, float (*fun) (float x));

void menu();
void menu_ecuaciones();
void menutrapecio();
void menutrapecio_multiple();
void menuSimpson() ;
void menuSimpsonMultiple();
void menuSimpsonTresOctavos();

#endif

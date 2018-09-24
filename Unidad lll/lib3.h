#ifndef lib3
#define lib3

float fun1 (float x);
float fun2 (float x);
float fun3 (float x);
float fun4 (float x);

void menutrapecio();
void trapecio(float a, float b, float (*fun)(float x));
void menu_ecuaciones();
void menu();
void menutrapecio_multiple();
void trapecioMultiple(float a,float b,int n,float (*fun)(float x) );

#endif

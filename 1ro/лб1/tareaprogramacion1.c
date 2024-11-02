#include <stdio.h>
#include <math.h>

int main(){

int a = 0;
int b = 0;
int c = 0;
int d = 0;

int numeradorSuma = 0;
int denominadorSuma = 0;

int numeradorResta = 0;
int denominadorResta = 0;




printf("эта программа вычисляет сумму и разность двух обыкновенных дробей\n");

scanf("%d %d %d %d",&a,&b,&c,&d);


numeradorSuma = (a*d)+(c*b);
denominadorSuma = b*d;

numeradorResta = (a*d)-(c*d);
denominadorResta = b*d;


printf("сумма дробей равна: %d/%d \nрасность дробей равна: %d/%d\n",numeradorSuma,denominadorSuma,numeradorResta,denominadorResta);



}
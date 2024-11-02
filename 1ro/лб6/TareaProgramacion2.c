#include <stdio.h>
#include <math.h>


int main(){

int i = 0;

int a = 0;
int b = 0;

int n = 0;

int x = 0;
int y = 0;

int x0 = 0;
int y0 = 0;

int r = 0;

int cuenta = 0;

printf("эта программа определяет сколько чисел падают в круге радиуса выбиранного вами \n ");
 printf("введите координаты (a и b) центра окружности\n");
 
 
 printf("введите значие a: \n");
 scanf("%d",&a);
 printf("введите значение b: \n");
 scanf("%d",&b);
 printf("введите значение радиуса\n");
 scanf("%d",&r);
 printf("введите количество точек вы введете\n");
 scanf("%d",&n);
 
 printf("введите координаты точек которые вы хотите сравнить \n ");
 
 
do{

    x0++;
    y0++;

    printf("введите значение х%d \n",x0);
    scanf("%d",&x);

    printf("введите значение y%d \n",y0);
    scanf("%d",&y);


    if((pow((pow(x-a,2)+pow(y-b,2)),0.5))<=r){

        cuenta++;

    }
i++;

}while(i < n);

printf("количество точек которые падают в круге равно %d\n ", cuenta);



}
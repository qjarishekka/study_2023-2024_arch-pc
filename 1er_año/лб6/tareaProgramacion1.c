#include <stdio.h>

int main(){

int i = 0;
int n =0;
int positivo = 0;
int negativo = 0;
int ceros = 0;
int NumeroIngresado = 0;

printf("эта программа даёт каличесво отрицательных положительных и нулей \n");


printf("сколько чисел вы введете?\n");
scanf("%d",&n);


printf("введите %d чисел\n",n);



do{

    scanf("%d",&NumeroIngresado);

    if(NumeroIngresado > 0){

        positivo++;
    }

    if(NumeroIngresado < 0){

        negativo++;
    }

    if(NumeroIngresado ==0){

        ceros++;

    }

i++;

}while(i < n);



printf("количество положительных: %d \n количество отрицательных: %d \n количество нулей: %d\n",positivo,negativo,ceros);

}
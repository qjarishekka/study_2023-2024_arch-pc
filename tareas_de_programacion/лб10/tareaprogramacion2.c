#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define lim 30
#define lim2 100

//////////////////////////////////
//AQUI SE DECLARAN LAS FUNCIONES//
//////////////////////////////////

char * ElNumero(int [], int );


///////////////////////
//INICIO DEL CODIGO////
///////////////////////



int main(){

int arreglo[lim];
int i = 0;
int n = 0;
int counter = 0;
int counter2 = 0;

printf("эта программа выводит первое число, которое удобледворяет уравенство Ak < An \n");


do{
    printf("сколько чисел вы ведёте? \nколичество должно удавлетворять неравество 0 < n < 30 \n");
    scanf("%d",&n);
}while(n<=0 || n>30);

do{
    counter = 0;

    printf("введите %d чисел, не должно быть ни одного нуля \n",n);

    for(i=0;i<n;i++){

        scanf("%d",&arreglo[i]);

        if(arreglo[i] == 0){

            counter++;

        }

    }


}while(counter != 0);



printf("%s\n",ElNumero(arreglo,n));


}


///////////////////////////////////////
//AQUI VAN LAS FUNCIONES///////////////
///////////////////////////////////////


char * ElNumero(int arreglo[], int n){

int counter2 = 0;
int i = 0;
char * salida;
char guardado[lim2];

for(i=0;i<n;i++){

    if(arreglo[i]< arreglo[n-1]){

        sprintf(guardado,"первое число, которое удавлетворяет неравенство Ak < An равно: %d",arreglo[i]);
        
        printf("%s",guardado);

        break;

    }else(counter2++);
}


if(counter2 == n){

    return "\nне существует число,которое удавлетворяет неравество  Ak < An : \n0\n";

}


strcpy(salida,guardado);
        
return salida;



}


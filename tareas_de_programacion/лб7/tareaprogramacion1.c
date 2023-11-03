#include <stdio.h>
#define lim 30

int main(){

int arreglo[lim];
int i = 0;
int n = 0;
int counter = 0;
int suma = 0;

printf("\n\nэта программа выводит сумму введённых чисел до первого нуля \n");

do{
printf("введите числа от 1 до 30 чтобы определить количество чисел вы введёте\n");
scanf("%d",&n);
}while(n<=0 || n >30);



do{
printf("введите %d числа. хотя бы одно число должен быть отрицательным \n",n);

    for(i=0;i<n;i++){

        scanf("%d",&arreglo[i]);
           
        if(arreglo[i]<0){
        counter++;
        }

    }

}while(counter == 0);

/*for(i=0;i<n;i++){

    printf("%d",arreglo[i]);

}*/


for(i=0;i<n;i++){

    if(arreglo[i] != 0){
    suma = suma + arreglo[i];
    }else(i=n);

}

printf("сумма равна: %d\n",suma);

}
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define lim1 10
#define limrand 11

int main() {

int n = 0;
int arreglo[lim1][lim1];
int random = 0;
int i = 0;
int j = 0;
int k = 0;
int suma = 0;
int min = limrand;

do{

printf("введите значение для \"n\" не больше десяти и не меньше нуля\n");

scanf("%d",&n);

}while(n<=0 || n >lim1);

srand(time(NULL));

for(i=0;i<n;i++){

    for(j=0;j<n;j++){
 
        arreglo[i][j] = rand() % limrand;

    }


}

for(i=0;i<n;i++){
    
    for(j=0;j<n;j++){
       
       printf("%d\t",arreglo[i][j]);
    
    }

    printf("\n\n");

}

for(i=0;i<n;i++){

    for(j=0;j<n;j++){

        if(j<n-i-1){

            suma = suma + arreglo[i][j];

        }
       
    }

}

for(i=n-1;i>-1;i--){

    for(j=n-1;j>-1;j--){

        if(j>n-i-1){

            if(arreglo[i][j] <= min){

                min = arreglo[i][j];

            }
        }

    }

}





printf("сумма элементов, расположенных выше побочной диагонали матрицы равна: %d\n  наименьшее значение среди элементов, расположенных ниже побочной диагонали матрицы равно: %d",suma,min);


}


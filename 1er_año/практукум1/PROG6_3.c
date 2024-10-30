#include <stdio.h>
#include <stdlib.h>
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


//que hace el programa?

printf("\nэта программа выводит сумму элементов, расположенных выше побочной диагонали матрицы\n");


//preguntar el valor de n
do{

    printf("введите значение для \"n\" не больше %d и не меньше нуля\n",lim1);

    scanf("%d",&n);

}while(n<=0 || n >lim1);


//semilla (семя) de random
srand(time(NULL));



//llenado de la matriz con numeros random
for(i=0;i<n;i++){

    for(j=0;j<n;j++){
 
        arreglo[i][j] = rand() % (limrand-1) + 1;

    }

}


//impresion de la matriz
for(i=0;i<n;i++){
    
    for(j=0;j<n;j++){
       
       printf("%d\t",arreglo[i][j]);
    
    }

    printf("\n\n");

}


//calcular la suma de numeros arriba de la diagonal
for(i=0;i<n;i++){

    for(j=0;j<n;j++){

        if(j<n-i-1){

            suma = suma + arreglo[i][j];

        }
       
    }

}


//calcular el menor numero bajo la diagonal en la matriz
for(i=n-1;i>-1;i--){

    for(j=n-1;j>-1;j--){

        if(j>n-i-1){

            if(arreglo[i][j] <= min){

                min = arreglo[i][j];

            }
        }

    }

}


//impresion de la respuesta
printf("сумма элементов, расположенных выше побочной диагонали матрицы равна: %d\n  наименьшее значение среди элементов, расположенных ниже побочной диагонали матрицы равно: %d\n",suma,min);


}


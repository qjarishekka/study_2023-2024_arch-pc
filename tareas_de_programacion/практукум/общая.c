#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define lim1 10
#define lim2 10
#define limrand 11

int main() {


//variables
int m = 0; 
int n = 0;
int arreglo[lim1][lim2];
int random = 0;
int i = 0;
int j = 0;
int suma = 0;
int max = 0;


//que hace el programa?
printf("\nэта программа выводит сумму максимальных элементов строк матрицы\n");


//preguntar los valores para n(filas) y m(columnas)
do{

printf("введите значение для \"n\" и \"m\" не больше %d и не меньше нуля\n",lim1);

scanf("%d",&n);
scanf("%d",&m);

}while(n<=0 || n >10 || m<=0 || m>10);


//semilla(семя) para rand
srand(time(NULL));

for(i=0;i<n;i++){

    for(j=0;j<m;j++){

        arreglo[i][j] = rand() % (limrand-1) + 1;

    }


}


//impresion de la matriz
for(i=0;i<n;i++){
    
    for(j=0;j<m;j++){
       
       printf("%d\t",arreglo[i][j]);
       }
    printf("\n\n");

}


//calculo de la suma maxima
for(i=0;i<n;i++){

    for(j=0;j<m;j++){

        if(arreglo[i][j]>= max){

            max = arreglo[i][j];

        }

    

    }

    suma = suma + max;
    max = 0;
}


//impresion de la suma
printf("сумма равна: %d\n",suma);

}
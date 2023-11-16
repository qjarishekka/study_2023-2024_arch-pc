#include <stdio.h>
#include<stdlib.h>
#include <time.h>


#define lim1 10         //количество строк
#define lim2 10         //количество столбцов
#define limrand 11

int main() {

int m = 0; 
int n = 0;
int arreglo[lim1][lim2];
int random = 0;
int i = 0;
int j = 0;
int max = 0;
int suma_temp = 0;


//que hace el programa?
printf("\nэта программа выводит наименьшая сумма столцов матрицы\n");


//preguntar el valor de n(filas) y m(columnas)
do{

    printf("введите значение для \"n\" и \"m\" не больше %d и не меньше нуля\n",lim1);

    scanf("%d",&n);
    scanf("%d",&m);

}while(n<=0 || n >lim1 || m<=0 || m>lim2);


//dar el valor maximo para la suma de elemtos de las columnas
max = limrand * n;


//semilla (семя) para rand
srand(time(NULL));
 

 //llenado de la matriz con numeros random
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



//calculo de la suma de valores de las columnas y su valor maximo
for(i=0;i<m;i++){

    for(j=0;j<n;j++){

        suma_temp = suma_temp + arreglo[j][i];

    }

    if(suma_temp <= max){

        max = suma_temp;

    }

    suma_temp = 0;


}


//impresion de la respuesta
printf("наименьшая сумма столцов равна: %d\n",max);



}


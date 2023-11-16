#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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


float media_geometrica_temporal = 0;
float multiplicacion_temporal = 1;
float medias_geometricas[lim1];
int numeros_mayores_a_la_media[lim2];
float exp;


//que hace el programa?
printf("\nэта программа выводит сумму максимальных элементов строк матрицы\n");


//preguntar los valores para n(filas) y m(columnas)
do{

printf("введите значение для \"n\" и \"m\" не больше %d и не меньше нуля\n",lim1);

scanf("%d",&n);
scanf("%d",&m);

}while(n<=0 || n >lim1 || m<=0 || m>lim2);


//semilla(семя) para rand
srand(time(NULL));

exp = 1.0/n;

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





for(j=0;j<m;j++){

    for(i=0;i<n;i++){

        multiplicacion_temporal = arreglo[i][j] * multiplicacion_temporal;

    }


    media_geometrica_temporal = pow(multiplicacion_temporal,exp);

    medias_geometricas[j] = media_geometrica_temporal;

    multiplicacion_temporal = 1;

}





for(i=0;i<lim2;i++){

    numeros_mayores_a_la_media[i] = 0;

}


for(j=0;j<m;j++){

    for(i=0;i<n;i++){

        if(arreglo[i][j]>medias_geometricas[j]){

            numeros_mayores_a_la_media[j]++;

        }

    }

}


for(i=0;i<n;i++){

    printf("\nколичество чисел выше чем средний геомерический в столбе %d равно: %d\n",i+1,numeros_mayores_a_la_media[i]);

}


}
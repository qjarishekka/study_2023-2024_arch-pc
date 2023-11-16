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

printf("эта программа выводит наименьшая сумма столцов матрицы");

do{

printf("введите значение для \"n\" и \"m\" не больше десяти и не меньше нуля\n");

scanf("%d",&n);
scanf("%d",&m);

}while(n<=0 || n >lim1 || m<=0 || m>lim2);


max = limrand * n;


srand(time(NULL));

for(i=0;i<n;i++){

    for(j=0;j<m;j++){

        arreglo[i][j] = rand() % limrand;

    }

}


for(i=0;i<n;i++){
    
    for(j=0;j<m;j++){
       
       printf("%d\t",arreglo[i][j]);
    
    }

    printf("\n\n");

}



for(i=0;i<m;i++){

    for(j=0;j<n;j++){

        suma_temp = suma_temp + arreglo[j][i];


    }

    if(suma_temp <= max){

        max = suma_temp;

    }

    suma_temp = 0;


}


printf("наименьшая сумма столцов равна: %d\n",max);



}


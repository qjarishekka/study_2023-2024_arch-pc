#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define lim 10  //limit of matrix
#define limrand 11
int main(){

int arreglo[lim][lim];
int i = 0;
int j = 0;
int n = 0;
srand(time(NULL));

printf("\nэта программа выводит две суммы расположенных ниже и выше главной диагонали\n");

do{

    printf("\nвведите значение \"n\" чтобы определить размер матрицы\n");

    scanf("%d",&n);


}while(n <= 0 || n > lim);


for(i=0;i<n;i++){
    
    for(j=0;j<n;j++){

        arreglo[i][j] = rand() % (limrand-1) + 1; 

    }

}


for(i=0;i<n;i++){
    
    for(j=0;j<n;j++){
       
       printf("%d\t",arreglo[i][j]);
    
    }

    printf("\n\n");

}





}
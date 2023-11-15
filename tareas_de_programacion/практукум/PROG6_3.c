#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define lim1 10
#define lim2 10
#define limrand 11

int main() {

int m = 0; 
int n = 0;
int arreglo[lim1][lim2];
int random = 0;
int i = 0;
int j = 0;
int k = 0;
int suma = 0;
int min = 0;

do{

printf("введите значение для \"n\" и \"m\" не больше десяти и не меньше нуля\n");

scanf("%d",&n);
scanf("%d",&m);

}while(n<=0 || n >lim1 || m<=0 || m>lim2);

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

for(i=0;i<n;i++){

    for(k=n;k>=0;k--){

        for(j=0;j<m;j++){

            suma = suma + arreglo[i][j];

        }



    }


} 

printf("сумма элементов, расположенных выше побочной диагонали матрицы равна: %d\n",suma);

}


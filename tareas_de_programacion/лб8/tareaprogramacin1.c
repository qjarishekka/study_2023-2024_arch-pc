#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define lim 10  //limit of matrix
#define limrand 11



#define sum 2

int main(){

int arreglo[lim][lim];


int i = 0;
int j = 0;
int n = 0;
int random1 = 0;
int random2 = 0;
int random3 = 0;
int random4 = 0;
int sumasup = 0;
int sumainf = 0;



int suma[sum];


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


/*
for(i=0;i<2;i++){

    do{

    random1 = rand() % n;
    random2 = rand() % n;

    }while(random1-random2>=0);



    do{

    random3 = rand() % n;
    random4 = rand() % n;

    }while(random3-random4<=0);

    suma[i] = arreglo[random1][random2] + arreglo[random3][random4];

}
*/

for(i=0;i<n;i++){
    
    for(j=0;j<n;j++){
       
        if(i-j<0){

            sumasup = sumasup + arreglo[i][j];

        }
    
    }

}

for(i=0;i<n;i++){
    
    for(j=0;j<n;j++){
       
        if(i-j>0){

            sumainf = sumainf + arreglo[i][j];

        }
    
    }

}





printf("\nдве суммы элементов, расположенных ниже и выше главной диагонали равны:\nвысшяя сумма: %d \nнижняя сумма: %d\n",sumasup,sumainf);









}
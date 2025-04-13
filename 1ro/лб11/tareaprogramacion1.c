#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define lim 10  //limit of matrix
#define limrand 11 //limite de los numeros random

#define sum 2 //limite de sumas


//////////////////////////////////
//AQUI SE DECLARAN LAS FUNCIONES//
//////////////////////////////////

int SumaSuperior(int arreglo[lim][lim], int n);
int SumaInferior(int arreglo[lim][lim], int n);


///////////////////////
//INICIO DEL CODIGO////
///////////////////////

int main(){

int arreglo[lim][lim];


int i = 0;
int j = 0;
int n = 0;
int sumasup = 0;
int sumainf = 0;



int suma[sum];



//semilla(семя) de los numeros random
srand(time(NULL));


// que hace este programa?
printf("\nэта программа выводит две суммы расположенных ниже и выше главной диагонали\n");


//ingreso del valor de la variable n para el tamaño de la matriz
do{

    printf("\nвведите значение \"n\" чтобы определить размер матрицы\n");

    scanf("%d",&n);


}while(n <= 0 || n > lim);



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




//suma de los numeros superiores a la diagonal principal

sumasup = SumaSuperior(arreglo,n);

//suma de numeros inferior a la diagonal principal


sumainf = SumaInferior(arreglo,n);



printf("\nдве суммы элементов, расположенных ниже и выше главной диагонали равны:\nвысшяя сумма: %d \nнижняя сумма: %d\n",sumasup,sumainf);



return 0;


}


///////////////////////////////////////
//AQUI VAN LAS FUNCIONES///////////////
///////////////////////////////////////



int SumaSuperior(int arreglo[lim][lim], int n){

int sumasup = 0;
int i = 0;
int j = 0;


for(i=0;i<n;i++){
    
    for(j=0;j<n;j++){
       
        if(i-j<0){      

            sumasup = sumasup + arreglo[i][j];

        }
    
    }

}

return sumasup;


}

////////////////////////////////////////////////////


int SumaInferior(int arreglo[lim][lim], int n){

int i = 0;
int j = 0;
int sumainf = 0;

for(i=0;i<n;i++){
    
    for(j=0;j<n;j++){
       
        if(i-j>0){

            sumainf = sumainf + arreglo[i][j];

        }
    
    }

}

return sumainf;

}

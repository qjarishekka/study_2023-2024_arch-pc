#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lim 1000

//////////////////////////////////
//AQUI SE DECLARAN LAS FUNCIONES//
//////////////////////////////////

int SumaDivisores(int Numero);



///////////////////////
//INICIO DEL CODIGO////
///////////////////////

int main(){

int A = 0;
int B = 0;
int C = 0;

int SumaDivisoresA = 0;
int SumaDivisoresB = 0;
int SumaDivisoresC = 0;

printf("эта программа выводит число, сумма делителей которого максимальна\n");

printf("Введите значения для A B и C:\n");

scanf("%d %d %d",&A,&B,&C);


SumaDivisoresA = SumaDivisores(A);
SumaDivisoresB = SumaDivisores(B);
SumaDivisoresC = SumaDivisores(C);


if(SumaDivisoresA >= SumaDivisoresB && SumaDivisoresA >= SumaDivisoresC){

    printf("число, сумма делителей которого максимальна: %d",A);

}else{

    if(SumaDivisoresB >= SumaDivisoresC){

        printf("число, сумма делителей которого максимальна: %d",B);


    }else{

        printf("число, сумма делителей которого максимальна: %d",C);

    }

}


}


///////////////////////////////////////
//AQUI VAN LAS FUNCIONES///////////////
///////////////////////////////////////

int SumaDivisores(int Numero){

int i = 0;
int suma = 0;


for(i=1;i<=Numero;i++){

    if(Numero % i == 0){

        suma++;

    }

}

return suma;

    
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define lim 10

char* SumaFraccinoes(int , int , int , int );


int main(){

int NumeradorA = 0;
int DenominadorA = 0;
int NumeradorB = 0;
int DenominadorB = 0;
char * respuesta;


printf("эта программа выводить сумму дробей\n");

do{

printf("введите 2 дроби\n");

printf("введите числителя превого дроби:\n");
scanf("%d",&NumeradorA);
printf("введите знаминателя превого дроби:\n");
scanf("%d",&DenominadorA);
printf("введите числителя второго дроби:\n");
scanf("%d",&NumeradorB);
printf("введите знаминателя второго дроби:\n");
scanf("%d",&DenominadorB);

}while(DenominadorA == 0 || DenominadorB == 0);



//respuesta = SumaFraccinoes(NumeradorA, DenominadorA, NumeradorB, DenominadorB);

printf("сумма дробей равна: %s\n",SumaFraccinoes(NumeradorA, DenominadorA, NumeradorB, DenominadorB));




}


///////////////////////////////////////
//AQUI VAN LAS FUNCIONES///////////////
///////////////////////////////////////

char* SumaFraccinoes(int a, int b, int c, int d){



int NumeradorSuma = 0;
int DenominadorSuma = 0;

int i = 0;
char respuesta[lim];
char * salida;

NumeradorSuma = (a*d) + (b*c);
DenominadorSuma = b*d;




for(i=2;i<=DenominadorSuma;i++){

        while(NumeradorSuma % i == 0 && DenominadorSuma % i == 0){

            NumeradorSuma = NumeradorSuma / i;
            DenominadorSuma = DenominadorSuma / i;

            printf("prueba %d\n",i);

        }

    }

sprintf(respuesta,"%d/%d",NumeradorSuma,DenominadorSuma);

strcpy(salida,respuesta);

if(NumeradorSuma == DenominadorSuma){

    salida = "1";

}


return salida;

}
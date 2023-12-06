#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define lim 1000

int NumeroDePalabrasIgualesALaPrimera(char frase[lim]){

int NumeroDeLetrasDeLaPrimeraPalabra = 0;
int NumeroDeLetras = 0;
int i = 0;
int NumeroDePalabrasDelMismoTamano = 0;
int InicioDePalabra = 0;



for(i=0;i<lim;i++){

    if(frase[i] == ' ' || frase[i] == '\n' || frase[i] == '\v'){

        i = lim;

    }

    NumeroDeLetrasDeLaPrimeraPalabra++;

    

}

NumeroDeLetrasDeLaPrimeraPalabra--;


for(i=0;i<lim;i++){

    if(frase[i] == ' ' || frase[i] == '\n' || frase[i] == '\v' || frase[i] == '\0'){

        if(i - InicioDePalabra == NumeroDeLetrasDeLaPrimeraPalabra ){

            NumeroDePalabrasDelMismoTamano++;

            

        }

        if(frase[i] == '\0'){

            i = lim;

        }

        InicioDePalabra = i+1;

    }

}




return NumeroDePalabrasDelMismoTamano;



}





int main(){

char CadenaDeGuardado[lim];
char * texto;


printf("\nэта программа выводит число повторений первого слова\n");
printf("введите строку\n");

fgets(CadenaDeGuardado,lim,stdin);



printf("число повторений первого слова: %d\n",NumeroDePalabrasIgualesALaPrimera(CadenaDeGuardado));

}
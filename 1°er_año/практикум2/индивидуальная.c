#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lim 20

char * SiNo(char frase[lim]){

int i = 0;
int NumeroDeLetras = 0;
int comprobador = 0;




for(i=0;i<lim;i++){

    if(frase[i] == ' ' || frase[i] == '\t' || frase[i] == '\v' || frase[i] == '\0'){

        i = lim;

    }else{

        NumeroDeLetras++;

    }

}


for(i=0;i<lim;i++){

    if(frase[i] == frase[NumeroDeLetras - i - 2]){

        comprobador = 1;
        
        if(i == NumeroDeLetras -1 -2){

            i = lim;

        }

    }else{

        comprobador = 0;
        i = lim;

    }

}


if(comprobador == 1){

    return "да";

}else{

    return "нет";

}



}



int main(){

char PalabraIngresada[lim];

printf("\nэта программа говорит, введенное слово ли палиндром\n");
printf("введите строку\n");

fgets(PalabraIngresada, lim, stdin);

printf("эта слово полиндром?: %s\n",SiNo(PalabraIngresada));


}
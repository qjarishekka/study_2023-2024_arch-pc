#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lim 10



char * FraccionReducida(char Fraccion[lim]){

char NumeradorCadena[lim];
char DenominadorCadena[lim];

int i = 0;
int InicioDenominador = 0;
int Numerador;
int Denominador;


for(i=0;i<lim;i++){

    if(Fraccion[i] != '/'){

        NumeradorCadena[i] = Fraccion[i];
        InicioDenominador++;

    }else{

        i = lim;

    }

}

for(i=InicioDenominador;i<lim;i++){

    if(Fraccion[i] != '\0'){

        DenominadorCadena[i] = Fraccion[i];

    }else{

        i = lim;

    }



}

Numerador = atoi(NumeradorCadena);
Denominador = atoi(DenominadorCadena);


printf("%s %s\n",NumeradorCadena,DenominadorCadena);

printf("%d  %d\n",Numerador,Denominador);










return "\nhola\n";


}



int main(){

int i = 0;
int EsUnaFraccion = 0;

char Fraccion1[lim];
char Fraccion2[lim];

printf("\nэта программа выводит обыкновенную несократимую сумму из введенных дробей\n");




do{

printf("\nвведите 2 дроби:\n");

fgets(Fraccion1,lim,stdin);
fgets(Fraccion2,lim,stdin);



for(i=0;i<lim;i++){

    if(Fraccion1[i] == '/'){

        EsUnaFraccion = 1;

    }

}

for(i=0;i<lim;i++){

    if(Fraccion2[i] == '/'){

        EsUnaFraccion = 1;

    }

}


}while(EsUnaFraccion == 0);

printf("%s",FraccionReducida(Fraccion1));




}
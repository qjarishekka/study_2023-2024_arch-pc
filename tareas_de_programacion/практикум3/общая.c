#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lim 10
#define limPrimos 10

char * suma(char FraccionA[lim], char FraccionB[lim]);

///////////////////////
//INICIO DEL CODIGO////
///////////////////////

int main(){

int i = 0;
int EsUnaFraccion = 0;
int UbicacionDeLDiagonal = 0;

char Fraccion1[lim];
char Fraccion2[lim];

printf("\nэта программа выводит обыкновенную несократимую сумму из введенных дробей\n");




do{

printf("\nвведите 2 дроби, знаминатели не могут быть нулем:\n");

fgets(Fraccion1,lim,stdin);
fgets(Fraccion2,lim,stdin);



for(i=0;i<lim;i++){

    if(Fraccion1[i] == '/'){

        EsUnaFraccion = 1;
        UbicacionDeLDiagonal = i;
        
    }
    
}

for(i=UbicacionDeLDiagonal;i<lim;i++){

    if(Fraccion1[i] == '0'){

        EsUnaFraccion = 0;
        
    }
    
}



for(i=0;i<lim;i++){

    if(Fraccion2[i] == '/'){

        EsUnaFraccion = 1;

    }

}

for(i=UbicacionDeLDiagonal;i<lim;i++){

    if(Fraccion2[i] == '0'){

        EsUnaFraccion = 0;
        
    }
    
}




}while(EsUnaFraccion == 0);

printf("сумма дробей равна: %s",suma(Fraccion1,Fraccion2));




}



///////////////////////////////////////
//AQUI VAN LAS FUNCIONES///////////////
///////////////////////////////////////




char * suma(char FraccionA[lim], char FraccionB[lim]){

int NumerosPrimos[lim] = {2,3,5,7,11,13,17,19,23,29};

int NumeradorFraccionA = 0;
int DenominadorFraccionA = 0;

int NumeradorFraccionB = 0;
int DenominadorFraccionB = 0;

int InicioDenominadorDeFracciones = 0;

int NumeradorSuma = 0;
int DenominadorSuma = 0;

int i = 0; 


char NumeradorFraccionCadenaA[lim];
char DenominadorFraccionCadenaA[lim];

char NumeradorFraccionCadenaB[lim];
char DenominadorFraccionCadenaB[lim];

char * Respuesta;


for(i=0;i<lim;i++){

    if(FraccionA[i] != '/'){

        NumeradorFraccionCadenaA[i] = FraccionA[i];
        InicioDenominadorDeFracciones++;
    
    }else{

        i = lim;

    }

}

strcpy(DenominadorFraccionCadenaA, FraccionA + InicioDenominadorDeFracciones+1);

InicioDenominadorDeFracciones = 0;

for(i=0;i<lim;i++){

    if(FraccionB[i] != '/'){

        NumeradorFraccionCadenaB[i] = FraccionB[i];
        InicioDenominadorDeFracciones++;
    
    }else{

        i = lim;

    }

}

strcpy(DenominadorFraccionCadenaB, FraccionB + InicioDenominadorDeFracciones+1);


NumeradorFraccionA = atoi(NumeradorFraccionCadenaA);
DenominadorFraccionA = atoi(DenominadorFraccionCadenaA);

NumeradorFraccionB = atoi(NumeradorFraccionCadenaB);
DenominadorFraccionB = atoi(DenominadorFraccionCadenaB);

NumeradorSuma = (NumeradorFraccionA * DenominadorFraccionB) + (NumeradorFraccionB * DenominadorFraccionA);
DenominadorSuma = DenominadorFraccionA * DenominadorFraccionB;



for(i=0;i<limPrimos;i++){

    while(NumeradorSuma % NumerosPrimos[i] == 0 && DenominadorSuma % NumerosPrimos[i] == 0){

        NumeradorSuma = NumeradorSuma / NumerosPrimos[i];
        DenominadorSuma = DenominadorSuma / NumerosPrimos[i];

    }
    
}

sprintf(Respuesta,"%d/%d",NumeradorSuma,DenominadorSuma);


if(NumeradorSuma == DenominadorSuma){

    return "1";

}

return Respuesta;

}

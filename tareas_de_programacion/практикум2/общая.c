#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lim 100
#define lim2 20

char * PalabraMasGrande(char * CadenaDeSimbolos){

int i = 0;
char palabra_temp[lim2];
int contador_de_letras = 0;
char frase[lim];
int inicio_de_palabra_mas_grande = 0;
int ubicacion_de_espacio[lim];
int inicio_de_palabra = 0;
int final_de_palabra = 0;
int palabra_mas_grande = 0;
int j = 0;

char LaPalabraMasGrande[lim2];
char * LaPalabra;


strcpy(frase,CadenaDeSimbolos);

for(i=0;i<lim;i++){

    if(frase[i] == '\0'){

            if( i - inicio_de_palabra >= palabra_mas_grande ){

            palabra_mas_grande = i - inicio_de_palabra;

            inicio_de_palabra_mas_grande = i - palabra_mas_grande;

            

            i = lim;

        }

        }


    if(frase[i] == ' ' || frase[i] == '\t' || frase[i] == '\v'){   

        
    
                if( i - inicio_de_palabra >= palabra_mas_grande ){

                    palabra_mas_grande = i - inicio_de_palabra;

                    inicio_de_palabra_mas_grande = i - palabra_mas_grande;



                }

                inicio_de_palabra = i;

        

    }
   
}


strcpy(LaPalabraMasGrande, frase + inicio_de_palabra_mas_grande);


for(i=palabra_mas_grande;i<lim2;i++){

    LaPalabraMasGrande[i] = '\0';

}


LaPalabra = LaPalabraMasGrande;





return LaPalabra;






}


int main(){

char * cadena;
char cadenaGuardado[lim];
char mensaje[lim2];



printf("\nэта программа выводит самое длинное слово из введенной строки\n");
printf("введите строку\n");

fgets(cadenaGuardado,90,stdin);

cadena = cadenaGuardado;





printf("%s\n",PalabraMasGrande(cadena));



}








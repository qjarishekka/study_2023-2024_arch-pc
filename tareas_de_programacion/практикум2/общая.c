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
int j = 0;


strcpy(frase,CadenaDeSimbolos);

for(i=0;i<lim;i++){

    if(frase[i] == ' ' || frase[i] == '\t' || frase[i] == '\v'){    
    
        ubicacion_de_espacio[j]= i;
        j++;


        if(i >= i - inicio_de_palabra_mas_grande){

            contador_de_letras = i - inicio_de_palabra_mas_grande ;

            inicio_de_palabra_mas_grande = i - contador_de_letras;

        }

    }

   

}

printf("%d\n",contador_de_letras);


return "hola";






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








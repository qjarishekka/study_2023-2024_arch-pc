//declaracion de librerias (объявление переменных)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lim 100 //максимальный размер строки 
#define lim2 20 //максимальный размер слова



char * PalabraMasGrande(char * CadenaDeSimbolos){


//переменные
int i = 0;
int inicio_de_palabra_mas_grande = 0;
int inicio_de_palabra = 0;
int palabra_mas_grande = 0;


// переменные типа "char"
char frase[lim];
char LaPalabraMasGrande[lim2];
char * LaPalabra;


strcpy(frase,CadenaDeSimbolos); // копирование строки "cadenadesimbolos" в строке "frase"


//начало поиска наибольшого слова
for(i=0;i<lim;i++){

   


    if(frase[i] == ' ' || frase[i] == '\t' || frase[i] == '\0'){   //поиск наибольшого слова

        
    
                if( i - inicio_de_palabra >= palabra_mas_grande ){

                    palabra_mas_grande = i - inicio_de_palabra;

                    inicio_de_palabra_mas_grande = i - palabra_mas_grande;



                }

                if(frase[i] == '\0'){

                    i = lim;
                }

                inicio_de_palabra = i+1;

        

    }
   
}



strcpy(LaPalabraMasGrande, frase + inicio_de_palabra_mas_grande); // копирование строки "frase" из позиции "inicodelapalabramasgrande" в "lapalabramasgrande" 


for(i=palabra_mas_grande;i<lim2;i++){ //удаление букв, которые не используются

    LaPalabraMasGrande[i] = '\0';

}


LaPalabra = LaPalabraMasGrande; //копирование





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





printf("наибольщое слово:%s\n",PalabraMasGrande(cadena));



}








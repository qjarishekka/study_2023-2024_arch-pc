//declaracion de variables (объявление библотек)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definir limite del arreglo (определять предел массива)
#define lim 30


//declarar funciones (объявление функций)
char * SiNo(int X, int Y);






//programa principal(начало главной программы)
int main(){



//объявление переменных
int A = 0;
int B = 0;

//impresion de texto (печатание текста)
printf("\nвведите 2 числа чтобы говорить если можно ли получить десятичную запись число А путем вычеркивания одной или более цифр числа\n");

//escaneo de variables (сканирование переменных)
scanf("%d %d", &A,&B);


//impresion de la repuesta(печетание ответа)
printf("%s\n",SiNo(A,B));

}



//////////////////////////
//AQUI VAN LAS FUNCIONES//
//////////////////////////


char * SiNo(int X, int Y){ //funcion SiNo requiere de 2 variables la primera el numero al que se le quitan las cifras el segundo el numero quitado 
    

//declaracion de variables (объявление переменных)   
int i = 0;
int nosepuede = 0;

//declaracion del arreglo (объевление массива)
char comprobador[lim];


//copiar la variable X en el arreglo
sprintf(comprobador,"%d",X);



//comprobacion del numero para encontrar un numero igual a Y
for(i=0;i<lim;i++){

    if(comprobador[i] == Y){

        nosepuede = 0;

    }else{

        nosepuede = 1;

    }

}


//definir que respuesta se envia

if(nosepuede == 0){

    return "НЕТ";

}else{

    return "ДА";

}

}
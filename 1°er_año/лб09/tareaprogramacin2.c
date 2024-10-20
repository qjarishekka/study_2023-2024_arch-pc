

#include <stdio.h>                  //declaracion de variables (объявление библотек)
#include <stdlib.h>
#include <string.h>


#define lim 30                      //definir limite del arreglo (определять предел массива)



char * SiNo(int X, int Y);          //declarar funciones (объявление функций)







int main(){                         //programa principal(начало главной программы)




int A = 0;                          //объявление переменных
int B = 0;


printf("\nвведите 2 числа чтобы говорить если можно ли получить десятичную запись число А путем вычеркивания одной или более цифр числа\n");//impresion de texto (печатание текста)


scanf("%d %d", &A,&B);              //escaneo de variables (сканирование переменных)



printf("%s\n",SiNo(A,B));           //impresion de la repuesta(печетание ответа)

}



//////////////////////////
//AQUI VAN LAS FUNCIONES//
//////////////////////////


char * SiNo(int X, int Y){          //funcion SiNo requiere de 2 variables la primera el numero al que se le quitan las cifras el segundo el numero quitado 
    


int i = 0;                          //declaracion de variables (объявление переменных)   
int nosepuede = 0;


char comprobador[lim];              //declaracion del arreglo (объевление массива)



sprintf(comprobador,"%d",X);        //copiar la variable X en el arreglo




for(i=0;i<lim;i++){                 //comprobacion del numero para encontrar un numero igual a Y

    if(comprobador[i] == Y){

        nosepuede = 0;

    }else{

        nosepuede = 1;

    }

}




if(nosepuede == 0){                 //definir que respuesta se envia

    return "НЕТ";

}else{

    return "ДА";

}

}
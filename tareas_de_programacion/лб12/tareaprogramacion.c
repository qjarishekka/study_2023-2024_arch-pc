#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define lim 100
#define limchar 10



int comprobacion(char entrada[lim]);


int main(){

int i = 0;
int j = 0;

int SumaPares = 0;
int SumaImpares = 0;
int respuesta = 0;

int arreglo[lim];
char temp[limchar];
char * check;



printf("\n\n\n\nэта программа вычисляет разность между суммой всех четных и суммой всех нечетных чисел в последовательлности");

printf("введите числа для последовательности (не больше чем 100 чисел)\nчтобы становиться напишите \"stop\":\n");

do{

j = j + 1;

scanf("%s",temp);
check = temp;


sscanf(temp,"%d",&arreglo[j-1]);


if(strcmp(temp,"stop") == 0){

    break;

}else{

    if(!comprobacion(temp)){

      sscanf(temp,"%d",&arreglo[j-1]);
     

    }else{

         j-= 1;
       
        

    }
    

}

}while(j != lim);

printf("последовательность: ");

for(i=0;i<j-1;i++){

  
    printf("%d ",arreglo[i]);

}


for(i=0;i<j-1;i++){

    if(arreglo[i]% 2 == 0){

        SumaPares += arreglo[i];

    }else{

        SumaImpares += arreglo[i];

    }


}

respuesta = SumaPares - SumaImpares;

if(respuesta < 0){

    respuesta *= -1;

}

printf("\nРазность между суммой всех четных и суммой всех нечетных чисел в последовательлности равна: %d\n",respuesta);

}





int comprobacion(char entrada[lim]){

int i = 0;
int salida = 0;

for(i=0;i<lim;i++){

    if(isdigit(entrada[i])){

        salida = 0;

    }else{

        salida = 1;

    }

return salida;

}



}
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define lim 100
#define limchar 10


int comprobacion(char entrada[lim]);

int main(){

printf("эта программа вычислает максимум бегущего геометрического среднего последовательности\n");
printf("введите числа для последовательности (не больше чем 100 чисел)\nчтобы становиться напишите \"stop\":\n");

int arreglo[lim];
char temp[limchar];
int SecuenciaPositivos[lim];
int numerocuadrado[lim];
int counter = 0;
int counter2 = 0;
float respuesta = 0;

float cadenademedia[lim];

char * check;


int i = 0;
int j = 0;

for(i=0;i<lim;i++){

    SecuenciaPositivos[i] = 0;
    numerocuadrado[i] = 1;

}




do{

j = j + 1;

scanf("%s",temp);
check = temp;


sscanf(temp,"%d",&arreglo[j-1]);


if(strcmp(temp,"stop") == 0){

    break;

}else{

    if(comprobacion(temp)){

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




printf("\n");





for(i=0;i<j-1;i++){

    if(arreglo[i] > 0){

        SecuenciaPositivos[i-counter2] = arreglo[i];
        
    }else{

        counter2++;

    }

printf("%d ", SecuenciaPositivos[i-counter2]);

}




printf("\n");


for(i=0;i<lim;i++){

    if(SecuenciaPositivos[i] != 0){

        counter++;

    }


}





for(i=0;i<counter;i++){

    for(j=0;j<=i;j++){

      numerocuadrado[i] = SecuenciaPositivos[j] * numerocuadrado[i];

    }

printf("%d ",numerocuadrado[i]);

}

printf("\n");












for(i=0;i<counter;i++){

    cadenademedia[i] = pow(numerocuadrado[i], 1.0 / (i+1) );

    printf("%f ",cadenademedia[i]);
}


for(i=0;i<counter;i++){

    if(cadenademedia[i] >= respuesta){

        respuesta = cadenademedia[i];


    }



}

printf("\nответ: %f\n",respuesta);




}












int comprobacion(char entrada[lim]){

int i = 0;
int salida = 0;
int cantidadnumeros = 0;
int counter = 0;



do{


    cantidadnumeros++;

    i++;



}while(entrada[i] != '\0');




if(entrada[0] == '-'){
for(i=1;i<cantidadnumeros;i++){

    if(isdigit(entrada[i])){

        counter++;

    }else{

        counter--;

    }


}

counter++;
printf("%d",counter);

}else{

for(i=0;i<cantidadnumeros;i++){

    if(isdigit(entrada[i])){

        counter++;

    }else{

        counter--;

    }


}

}



//printf("%d %d",cantidadnumeros,counter);


if(cantidadnumeros == counter){

    return 1;

}else{

    return 0;

}



}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char * funcion(int a, int b, int c);


int main(void){

int x,y,z;

char R[30];

scanf("%d %d %d",&x,&y,&z);
 
strcat(R,funcion(x,y,z));

printf("%s\n",R);



}




char * funcion(int a, int b, int c){ //a = 1 coeficiente b = segundo coeficiente c = tercer coeficiente d = numero de raiz.

float discriminante = 0;
float respuesta1 = 0;
float respuesta2 = 0;

char respuestas[8];

char * RespuestasSalida;



discriminante = ((b*b)+(-4)*a*c);


if(discriminante >= 0){

    respuesta1 = (-b + pow((discriminante),0.5)) / (2*a);
    respuesta2 = (-b - pow((discriminante),0.5)) / (2*a);

    sprintf(respuestas,"%f",respuesta1);

    RespuestasSalida = respuestas;

    return RespuestasSalida;


}else{

    return "no hay respuesta";

}

}
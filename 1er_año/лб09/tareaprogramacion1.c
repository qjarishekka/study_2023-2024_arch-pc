#include <stdio.h>
#include <math.h>
#include <string.h>

//////////////////////////////////
//AQUI SE DECLARAN LAS FUNCIONES//
//////////////////////////////////

char * respuesta(int a, int b, int c);


///////////////////////
//INICIO DEL CODIGO////
///////////////////////

int main(){

  int x = 0;
  int y = 0;
  int z = 0;
  char R[100];

  

  do{

    printf("введите значение a, b и c для решения выражения ax^2 + bx + c  a должен быть больше нуля\n");

    scanf("%d %d %d",&x,&y,&z);


  }while(x == 0);

  

  strcpy(R,respuesta(x,y,z));

  //printf("%s\n",respuesta(x,y,z));
  printf("%s\n",R); //activar solo en windows y desctivar la linea de arriba

}



////////////////////////////////
// LAS FUNCIONES EMPIEZAN AQUI//
//////////////////////////////// 


char * respuesta(int a, int b, int c){

float discriminante = 0;

float raiz1;
float raiz2;

char raizL[100];
char * raizsalida;





discriminante = (b*b + ((-4)*a*c));




if(discriminante >= 0){


  

  raiz1 = (-b + discriminante)/(2*a);

  raiz2 = (-b - discriminante)/(2*a);

  sprintf(raizL,"%f и %f - эти корни",raiz1,raiz2);

  raizsalida = raizL;

  return raizsalida;

}else{
  return "нет решения";
  }


} 
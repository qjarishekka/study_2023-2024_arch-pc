#include <stdio.h>
#include <math.h>
#include <string.h>

char * respuesta(int a, int b, int c){

float discriminante = 0;

float raiz1;
float raiz2;

char raizL[30];
char * raizsalida;





discriminante = (b*b + ((-4)*a*c));




if(discriminante >= 0){


  

  raiz1 = (-b + discriminante)/(2*a);

  raiz2 = (-b - discriminante)/(2*a);

  sprintf(raizL,"%f и %f",raiz1,raiz2);

  raizsalida = raizL;

  return raizsalida;

}else{
  return "no hay respuesta";
  }


} 






void main(void){

  int x,y,z;
  char R[30];

  

  scanf("%d %d %d",&x,&y,&z);

  strcpy(R,respuesta(x,y,z));

  printf("%s\n",R);

}
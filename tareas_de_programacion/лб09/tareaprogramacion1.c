#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char * respuesta(int a, int b, int c){

char * res = "no hay respuesta";

int discriminante = 0;
int respuesta1,respuesta2;


discriminante = (b*b + ((-4)*a*c));

if(discriminante >= 0){

  respuesta1 = (-b + discriminante)/(2*a);
  respuesta2 = (-b - discriminante)/(2*a);

  res = 

}





  return res;

} 




void main(void){

  int x,y,z;

  scanf("%d %d %d",&x,&y,&z);

  printf("%s\n",respuesta(x,y,z)); 

}
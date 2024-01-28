#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define lim 10
int main(){
int i = 0;
char LaLista[lim];

srand(time(NULL));



for(i=0;i<10;i++){

LaLista[i] = rand() % 10;

}

for(i=0;i<10;i++){

printf("%d ",LaLista[i]);

}


}
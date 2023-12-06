#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//////////////////////////////////
//AQUI SE DECLARAN LAS FUNCIONES//
//////////////////////////////////
int NOK(int a, int b);

int NOD(int c, int d);

///////////////////////
//INICIO DEL CODIGO////
///////////////////////

int main(){

int X = 0;
int Y = 0;
int Z = 0;

int NOKXY = 0;
int NOKYZ = 0;
int NOKXZ = 0;

int i = 0;

printf("эта программа выводит два числа из трех, чтобы НОК этой пары был бы наибольшим.\nвводите значения для A B и C\n");

scanf("%d %d %d",&X,&Y,&Z);

NOKXY = NOK(X,Y);
NOKYZ = NOK(Y,Z);
NOKXZ = NOK(X,Z);

if(NOKXY >= NOKYZ && NOKXY >= NOKXZ){

    printf("%d %d\n",X,Y);

}else{

    if(NOKYZ >= NOKXZ){

        printf("%d %d\n",Y,Z);

    }else{

        printf("%d %d\n",X,Z);

    }

}



}




///////////////////////////////////////
//AQUI VAN LAS FUNCIONES///////////////
///////////////////////////////////////

int NOK(int a, int b){

int nok = 0;

nok = (a * b)  / NOD(a,b);

return nok;


}

int NOD(int c, int d){

    while(c != d){

        if(c>d){

            c = c - d;

        }else{

            d = d - c;

        }


    }

    return c;

}
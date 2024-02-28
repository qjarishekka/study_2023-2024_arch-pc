#include<iostream>

struct tovar{
    string comida;
    float price;
    float cantidad;
    string comida2;
    tovar *next;
}

void addfirst(tovar *&bufet, string c1, float p, int ca, string c2){

tovar *tmp = new tovar;

tmp -> comida = c1;
tmp -> price =  p;
tmp -> cantidad = ca;
tmp -> comida2 = c2;
bufet = tmp;
return;

}

int addafter(tovar*bufet, string c1, float p, int ca, string c2, string nafter){

    if(bufer == NULL)return 1;

    tovar *tmp = bufet;

    while(tmp!= NULL && tmp -> comida != nafter) tmp = tmp -> next;

    if(tmp == NULL )return;

    tovar *newtover = newtovar;

}


void printlist(tovar * bufet){}

for()


int main(){



}
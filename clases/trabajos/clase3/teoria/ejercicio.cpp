#include<iostream>
using namespace std;

struct tovar{
    string comida;
    float price;
    float cantidad;
    tovar *next;
};

void addfirst(tovar *&bufet, string c1, float p, int ca){

tovar *tmp = new tovar;

tmp -> comida = c1;
tmp -> price =  p;
tmp -> cantidad = ca;
tmp -> next = bufet;
bufet = tmp;

}

int addafter(tovar*bufet, string c1, float p, int ca, string nafter){

    if(bufet == NULL){

        return 1;
    
    }

    tovar *tmp = bufet;

    while(tmp!= NULL && tmp -> comida != nafter){

         tmp = tmp -> next;

    }

    if(tmp == NULL ){

        return 1;

    }

    tovar *newtovar = new tovar;

    newtovar -> comida = c1;
    newtovar -> price = p;
    newtovar -> cantidad = ca;
    newtovar -> next = tmp -> next;
    tmp -> next = newtovar;
    return 0;



}


void printlist(tovar * bufet){

    if(bufet == NULL){

        cout<< "список пуст!"<< endl;
        return;


    }

    tovar *tmp = bufet;

while(bufet != NULL){

    cout <<tmp -> comida<< endl;
    cout <<tmp -> price<< endl;
    cout <<tmp -> cantidad<< endl;
    tmp = tmp -> next;
   
}



}

int addbefore(tovar*bufet, string c1, float p, int ca, string bafter){

    if(bufet == NULL){

        return 1;
    
    }

    tovar * newtovar = new tovar;

    






}




int main(){

tovar *bufet = NULL;
printlist(bufet);
addfirst(bufet,"puncake",25,2);
addafter(bufet,"cake",55,20,"puncake");
printlist(bufet);
return 0;


}
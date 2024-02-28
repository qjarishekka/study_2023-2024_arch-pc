#include<iostream>
using namespace std;

struct tovar{
    
    string name;
    float price;
    int amount;
    tovar *next;

}

void addfirst(tovar *&bufet, string n, float p, int am){

tovar * tmp = new tovar;
tmp -> name = n;
tmp -> price = p;
tmp -> amount = am;
tmp -> next = bufet;
bufet = tmp;
return;

}

int addafter(tovar *bufet, string n, float p, int am, int am, string nafter){

    if(bufet == NULL){

        return 1;

    }

    tovar *tmp = bufet;

    while(tmp!=NULL && tmp->name!=nafter){

        tmp = tmp -> next;

    } 

    if(tmp == NULL) return;

    tovar *newtovar = new tovar;

    //<ввод данных в newtovar>

    newtovar -> next = tmp -> next;
    tmp -> next = newtovar;

    return 0;

}


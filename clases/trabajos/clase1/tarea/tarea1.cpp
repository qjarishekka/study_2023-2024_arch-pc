#include <iostream>

struct nodo{

        string letras;
        int numeros;
        double grandesnumeros;
        nodo *next;

};

void addfirst( nodo *&lista, string l, int n, double gn){



nodo *tmp = new nodo;

tmp -> letras = letras;
tmp -> numeros = n;
tmp -> grandesnumeros = gn;

tmp -> next = lista;

lista = tmp;


}


void addlast(nodo * lista, string l, int n, double gn){

nodo * tmp = new nodo

tmp -> letras = l;
tmp -> numeros = n;
tmp -> grandesnumeros = gn;

tmp -> next = lista;


}

int addafter(nodo*lista, string l,  int n, double gn, string nafter){

    if(lista == NULL){

        return 1;
    
    }

    nodo *tmp = lista;

    while(tmp!= NULL && tmp -> letras != nafter){
         tmp = tmp -> next;
    }

    if(tmp == NULL ){
        return 1;
    }

    nodo *newnodo = new nodo;

    newnodo -> letras = l;
    newnodo -> numeros = ca;
    newnodo -> grandesnumeros = gn;
    newnodo -> next = tmp -> next;
    tmp -> next = newnodo;
    return 0;



}

int addbefore(nodo *lista, string l, int n, double gn, string nbefore){


nodo * tmp = lista;
nodo * tmp2 = lista;

while(tmp != NULL && tmp->letras != nbefore){

tmp = tmp->next;

if(tmp -> letras != nbefore){

tmp2 = tmp;

}

}

nodo *newnodo = new nodo;

newnodo -> letras = l;
newnodo -> numeros = n;
newnodo -> grandesnumeros = gn;
newnodo -> next = tmp-> next;

tmp2 ->next = newnodo;

}





int main(){





}
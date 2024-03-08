#include <iostream>

using namespace std;

struct nodo{

        string letras;
        int numeros;
        double grandesnumeros;
        nodo *next;

};

void addfirst( nodo *&lista, string l, int n, double gn){



    nodo *tmp = new nodo;

    tmp -> letras = l;
    tmp -> numeros = n;
    tmp -> grandesnumeros = gn;

    tmp -> next = lista;

    lista = tmp;


}


void addlast(nodo * lista, string l, int n, double gn){

    nodo * tmp = new nodo;

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

    while(tmp != NULL && tmp -> letras != nafter){
         tmp = tmp -> next;
    }

    if(tmp == NULL){
        return 1;
    }

    nodo *newnodo = new nodo;

    newnodo -> letras = l;
    newnodo -> numeros = n;
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
    newnodo -> next = tmp;

    tmp2 ->next = newnodo;


    return 0;
}

int delnode(nodo *lista, string n){

    nodo * tmp = lista;
    nodo * tmp2 = tmp;

    while(tmp != NULL && tmp->letras != n){

        tmp = tmp->next;

    if(tmp -> letras != n){
        tmp2 = tmp;
    }

    } 

    tmp2 ->next = tmp ->next;

    delete tmp;

    return 0;
}

int printlist(nodo *lista){

    nodo * tmp = lista;






    while(tmp->next != NULL){

        cout << tmp -> letras<<endl;
        cout << tmp-> numeros<<endl;
        cout << tmp -> grandesnumeros<<endl;
        cout<<endl;
        tmp = tmp ->next;
    }


    cout << tmp -> letras<<endl;
    cout << tmp-> numeros<<endl;
    cout << tmp -> grandesnumeros<<endl;
    cout<<endl<<endl;
    return 0;
    
}


int main(){

nodo * lista = NULL;

/*
string a = "patata";
string b = "tomate";
string c = "camote";c 
string d = "rabanos";
*/


addfirst(lista,"patata",5,100);
printlist(lista);


addfirst(lista,"tomate",5,200);
printlist(lista);

addfirst(lista,"camote",6,300);
printlist(lista);

addafter(lista,"rabanos",6,400,"tomate");
printlist(lista);

addbefore(lista,"yuka",7,500,"patata");
printlist(lista);

delnode(lista,"rabanos");
printlist(lista);

return 0;

}
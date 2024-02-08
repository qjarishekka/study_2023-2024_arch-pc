#include <iostream>
#include <time.h>
using namespace std;

void qs(int X[], int inicio, int fin){

int izq, der, pivote, aux;
izq = inicio;
der = fin;
pivote = X[(izq+der)/2];


do{

    while(X[izq] < pivote && izq < fin){

        izq++;

    }

    while(X[der] > pivote && der > inicio){

        der--;

    }

    if(izq <= der){

        aux = X[izq];
        X[izq] = X[der];
        X[der] = aux;
        izq++;
        der--;


    }

}while(izq <= der);

if(inicio <= der){

    qs(X,inicio,der);

}

if(fin > izq){

    qs(X,izq,fin);

}


}






int main (){


srand(time(NULL));

int i = 0;
int j = 0;

int buff = 0;

int * X;
int n = 10;
X = new int [n+2];


for(i=0;i<n ;i++){
    X[i] = (rand()%10000)/100 - 50;

}

cout << "неупарядочный массив";

for(i = 0; i<n;i++){

    cout << X[i]<< endl;

}
 
 cout << endl << "упорядочный массив\n";

qs(X,0,n);

for(i=0;i<n;i++){

cout<< X[i]<<endl;

}

return 0;
}
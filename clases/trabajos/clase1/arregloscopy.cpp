#include <iostream>
#include <time.h>
using namespace std;




int compare(int X[], int Y[], int largo){

int i = 0;
int salida = 0;

    for(i=0;i<largo;i++){

        if(X[i] != Y[i]){

            return 0;

        }else{

            salida = 1;

        }


    }


    return salida;

}






int qs(int X[], int inicio, int fin, int largo){

int izq, der, pivote, aux;


int * Y;
int n = largo;
Y = new int [n+1];



izq = inicio;
der = fin;
pivote = X[(izq+der)/2];


int counter1= 0;
int counter2 = 0;

int i = 0;



for(i=0;i<largo;i++){

    Y[i] = X[i];

}



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
        
       if(!compare(X,Y,largo)){

        counter1++;
        
       cout<<endl <<"изменение "<<endl;

        for(i=0;i<largo;i++){

            cout<< X[i]<<endl;


        }
        cout<<endl;
        
       }
       
       

    }



}while(izq <= der);




if(inicio <= der){

   counter1 = counter1 +  qs(X,inicio,der,largo);


}

if(fin > izq){

    counter1 = counter1 + qs(X,izq,fin,largo);

}



return counter1;

}






int main (){


srand(time(NULL));

int i = 0;

int * X;
int n = 10;
int cuenta= 0;
cout << "введите количество введённых данных:" << endl;
cin >> n;


X = new int [n+1];


for(i=0;i<n ;i++){
    X[i] = (rand()%10000)/100 - 50;

}

cout << "неупарядочный массив\n";

for(i = 0; i<n;i++){


    cout<< X[i]<< endl;

}
 
// cout << endl << "упорядочный массив\n";

cuenta = qs(X,0,n,n);




cout<<"salida"<<endl;
for(i=0;i<n;i++){

cout<< X[i]<<endl;

}



cout << endl<< endl;

cout << "подсчет производных перестановок:" << cuenta<< endl;

return 0;
}
#include <iostream>
#include <time.h>
using namespace std;



int qs(int X[], int inicio, int fin, int largo){  //функция для сортировки массива

int izq, der, pivote, aux;    // некоторые переменные для работы сортировки


izq = inicio;                   // сначала даём переменным значения индексов первого и последнего переменных массива
der = fin;


pivote = X[(izq+der)/2];    // даём переменнему "pivote" любое значение массива, который находится около центра массива


int counter1= 0;            // это переменный служит для счета сколького циклов перестановок совершены


int i = 0;              // переменный для работы команды "for"


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
        
       counter1++;
        
       cout<<"изменение "<<endl;

        for(i=0;i<largo;i++){

            cout<< X[i]<<endl;


        }
        cout<<endl;
        

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

cuenta = qs(X,0,n-1,n);




cout<<"salida"<<endl;
for(i=0;i<n;i++){

cout<< X[i]<<endl;

}



cout << endl<< endl;

cout << "подсчет производных перестановок:" << cuenta<< endl;

return 0;
}
#include <iostream>
#include <time.h>
using namespace std;

int compare(int X[], int Y[], int largo){   //функция для сравнение массивов 

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






int qs(int X[], int inicio, int fin, int largo){        //функция для сортировки массива

int izq, der, pivote, aux;              //необходимые переменные


int * Y;                                //массив который будет сравниваться
int n = largo;
Y = new int [n+1];



izq = inicio;                           //переменные которые определяет такие числа, которые обменяются
der = fin;
pivote = X[(izq+der)/2];                //центральное число, от которого зависит обмен


int counter1= 0;                        //переменная, которая сохраняет количество перестановок
int counter2 = 0;

int i = 0;                              



for(i=0;i<largo;i++){               // копирование массива на массив "Y"

    Y[i] = X[i];

}



// начало алгоритма

do{

    while(X[izq] < pivote && izq < fin){        //поиск индекса одного числа, которое будет обменяться

        izq++;                                     

    }

    while(X[der] > pivote && der > inicio){         //поиск вторового индекса другого числа, которое будет обменяться

        der--;

    }

    if(izq <= der){                             //  обмен чисел 

        aux = X[izq];
        X[izq] = X[der];
        X[der] = aux;
        izq++;
        der--;
        
       if(!compare(X,Y,largo)){                     //сравнение массивов

        counter1++;                                 //увеличивем на 1 значение переменной
        
        cout<<endl <<"изменение "<<endl;            

        for(i=0;i<largo;i++){                       // печатаем массив и массив после перестановки

            cout<< X[i] 
            << "\t"<< Y[i] 
            <<endl;


        }
        cout<<endl;
        
       }
       
       

    }



}while(izq <= der);


if(!compare(X,Y,largo)){                                // еще раз деляем перестановку от первого числа до центра массива

if(inicio <= der){

   counter1 = counter1 +  qs(X,inicio,der,largo);


}
}

if(!compare(X,Y,largo)){                                 // еще раз деляем перестановку от центра массива до последного числа 

if(fin > izq){

    counter1 = counter1 + qs(X,izq,fin,largo);

}
}




return counter1;                //возвращается количество перестановок 

}






int main (){


srand(time(NULL));              // семя

int i = 0;                          // необходимые переменные

int * X;
int n = 10;
int cuenta= 0;
cout << "введите количество введённых данных:" << endl;     //введите количество чисел будет в массиве
cin >> n;


X = new int [n+1];          // создание массива


for(i=0;i<n ;i++){                          //заполнение массива
    X[i] = (rand()%10000)/100 - 50;

}

cout << "неупарядочный массив\n";

for(i = 0; i<n;i++){                        // печатание массива


    cout<< X[i]<< endl;

}
 
// cout << endl << "упорядочный массив\n";

cuenta = qs(X,0,n-1,n);         //сортировака и записание количества перестановок на переменой "cuenta"




cout<<"salida"<<endl;
for(i=0;i<n;i++){           //печатание упорядоченого массива 

cout<< X[i]<<endl;

}



cout << endl<< endl;

cout << "подсчет производных перестановок:" << cuenta<< endl;  // печатание упорядоченного массива

return 0;
}
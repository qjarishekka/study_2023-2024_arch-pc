#include <iostream>
#include <string.h>

using namespace std;

int calcularpi(double precision){

cout<<"calculo de pi"<<endl;

//резервирование памяти

int Largo_memoria = (precision * 10) / 3;
int largopi = precision;

cout <<"largo de memoria "<< Largo_memoria<< endl<<endl;

int *calculo = new int[Largo_memoria];
int *pi = new int[largopi];

//переменные команд for 
int i;
int j;
int l = 0;


//переменные для сохранения временных чисел
int multiplicacion = 0;
int suma = 0;
int presto = 0;

//инициализация массив(остаток)
for(i = 0; i < Largo_memoria; i++){

    calculo[i] = 2;

}

/////////////////////////////////////////////
// начало алгоритма/////////////////////////
//////////////////////////////////////////////

for(j = 0; j < precision;j++){//цикл для сохранение знаков Пи

    for(i = Largo_memoria-1; i > -1; i--){//цикл для вычисления знаков Пи

        if(i == 0){//вычисление под номером 0

            multiplicacion = calculo[i] * 10;

            suma = multiplicacion + presto;

            presto = suma/10;

            calculo[i] = suma %10;


            /////////////////////////////////////
            /////слежение неправильных знаков////
            /////////////////////////////////////

            if(presto<10){// когда знак строго меньше чем 10 не сделать ничего
            pi[j] = presto;
            presto = 0;
            }else{ //когда знак больше чем 10 перевычислать знаки

                pi[j-l] = presto %10;
                presto = presto / 10;
                l++;
                pi[j-l] +=presto; 

                while(pi[j-l]>9){


                    presto = pi[j-l];
                    
                    pi[j-l] = presto % 10;

                    l++;

                    presto = presto/10;

                    pi[j-l] = presto;

                }

                presto = 0;

            }


        }else{//вычисление под номером n-ем n-1 n-2 ..... 1.


            multiplicacion = calculo[i] * 10;

            suma = multiplicacion + presto;

            calculo[i] = suma % ((i*2) +1);

            presto = (suma/((i*2) + 1)) * i;


        }

    }

}


//печатание номера Пи на экран
cout<<pi[0]<<",";
for(int m = 1; m< precision;m++){
cout<< pi[m];

}

//конец
cout <<endl;
return 0;

}


int main(){

double precision;

cout<<"сколько знаков Пи вы хотите вычислить?: ";
//ввод желанное количество знаков
cin>> precision;    
                    //3,1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
                    //
calcularpi(precision);

}
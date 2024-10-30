#include <iostream>

using namespace std;

int progresionAritmetica( int, int, int);

int counter = 0;

int main(){

    int numeroInicial;
    int d;
    int n;

cin>> numeroInicial;
cin>> d;
cin>> n;

cout<<progresionAritmetica( numeroInicial, d,n );


    return 0;
}

int progresionAritmetica( int anterior, int d, int n){

int suma = anterior + d;
counter ++;

int respuesta;

if(counter != n){
 respuesta = progresionAritmetica(suma, d, n);

}else{

    respuesta = suma;
}

return respuesta;


}
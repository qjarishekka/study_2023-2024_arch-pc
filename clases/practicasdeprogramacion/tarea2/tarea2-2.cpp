#include<iostream>
#include <iomanip>

using namespace std;

int numero_de_operaciones_aritmeticas = 0;

int pow(int numero,int potencia){

int i = 0;

if(potencia == 0){

    return 1;

}

for(i = 1; i < potencia ; i++){

    numero = numero * -1;

    numero_de_operaciones_aritmeticas++;

}


//cout<<numero<<endl;


return numero;

}


long double calculopi(int precision){

int i = 0;

long double pi = 0.0;

long double numerador = 0;
long double denominador = 0;

long double sumando = 0.0;

for(i=0;i<precision;i++){

numerador = (pow(-1,i) * 4) ;
denominador = ((2*i) + 1 );

sumando = numerador / denominador;

pi = pi + sumando;


}


return pi;

}


int main(){

//3,141592653589793

long double pi = calculopi(1000000);

cout << setprecision(17);

cout << pi << endl;

}

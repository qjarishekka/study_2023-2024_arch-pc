#include<iostream>
#include <iomanip>

using namespace std;

double numero_de_operaciones_aritmeticas = 0;

int pow(int numero,int potencia){

int i = 0;

int resultado = numero;

if(potencia == 0){

    return 1;

}

for(i = 1; i < potencia; i++){

    resultado = numero * resultado;

    numero_de_operaciones_aritmeticas++;

}

return resultado;

}


long double calculopi(int precision){

int i = 0;

long double pi = 0.0;

long double numerador = 0;
long double denominador = 0;

long double sumando = 0.0;

for(i=0;i<precision;i++){

numerador = (pow(-1,i) ) ;
denominador = ((2*i) + 1 );

sumando = (numerador / denominador);


pi = pi + sumando;

numero_de_operaciones_aritmeticas += 4;

}

pi *= 4;
numero_de_operaciones_aritmeticas++;
return pi;

}


int main(){

//3,141592653589793

long double pi = calculopi(9999990);  //9999990

cout << setprecision(17);

cout << pi << endl;
cout << "количество арифметических операций: "<< numero_de_operaciones_aritmeticas<<endl;

}

#include <iostream>
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





double factorial(double numero){

    if(numero == 1){

        return 1;

    }

    numero =  numero * factorial(numero -1);
    numero_de_operaciones_aritmeticas++;

return numero;
}



double calculopi(int precicion){

double pi = 12.0;

double i = 0;

double sumando = 0.0;

for(i = 0; i<precicion;i++){

sumando = (pow(-1,i) * (factorial(6*i)) * ((545140134 * i) + 13591409)) / (  (factorial(3*i)) * (pow(factorial(i),3)) * (pow(640320, (3*i) + 3.0/2))   );

pi = pi + sumando;

}

pi = 1 / pi;


return pi;

}





int main(){

long double pi = calculopi(2);

cout<< setprecision(17);
cout << pi << endl;

}
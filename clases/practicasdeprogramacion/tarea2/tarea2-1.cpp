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




long double calculopi(int precicion){

double i =0;

long double pi = 3.0;
long double sumando = 0.0;


for(i=0;i<precicion;i++){


    sumando = (pow((-1),i)*(  4.0/((2+(2*i))*(3+(2*i))*(4+(2*i))) ));
    pi = pi + sumando;

    //cout<<sumando;
}

return pi;
}

int main(){

    long double pi = calculopi(40000); //3,141592653589793  735

    cout<< setprecision(17);
    cout << pi <<endl<<endl;

}
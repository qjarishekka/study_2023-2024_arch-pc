#include <iostream>

using namespace std;

int numero_de_operaciones_aritmeticas = 0;

int pow1(int numero,int potencia){

int i = 0;

for(i = 0; i < potencia ; i++){

    numero *= numero;
    numero_de_operaciones_aritmeticas++;
}


}

int calculopi1(int precicion){

int i =0;

int pi = 3;

for(i=0;i<precicion;i++){

    //pi = pi + (pow1(-1,i)*(pi/((2+(2*i))*(3+(2*i))*(4+(2*i)))));

}

return pi;
}

int main(){

    int pi = 5;//calculopi1(15);

    cout<<"hola"<<endl;
    cout << pi <<endl;


}
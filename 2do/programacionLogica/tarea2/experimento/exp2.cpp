#include <iostream>
#include<stdlib.h>
using namespace std;

int main(){



string ingreso = " ";

int counter = 0;

string * valores = new string[counter];



while(ingreso != "exit"){

cin>>ingreso;
counter++;

string * aux = new string[counter];

for(int i = 0; i<counter-1 ; i++){
    aux[i] = valores[i];
}

aux[counter-1] = ingreso;
delete[]valores;

valores = aux;


}

for(int i = 0; i< counter; i++)
    cout<<valores[i]<<endl;

}
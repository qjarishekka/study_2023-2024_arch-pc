#include <iostream>

using namespace std;

double calcularpi(int precision){

//reservar memoria

int Largo_memoria = (precision * 10) / 3;

cout << Largo_memoria<< endl;

int i;
int *calculo = new int[Largo_memoria];

int suma = 0;
int presto = 0;


for(i = 0; i < Largo_memoria; i++){

    calculo[i] = 2;

}


// empieza el algoritmo
for(i = Largo_memoria-1; i == -1; i--){  //fijarse aqui si hay error







}










for(i = 0; i < Largo_memoria; i++){

    cout<<calculo[i];

}




cout <<endl;
return 0;

}





int main(){

int precision;


cin>> precision;

calcularpi(precision);


}
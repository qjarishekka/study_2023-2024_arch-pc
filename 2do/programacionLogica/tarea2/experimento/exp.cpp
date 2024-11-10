#include<iostream>
#include<string>
#include<typeinfo>

using namespace std;

int permutacion(int alfa){

int beta;

beta = 1;

while(alfa > 1){

beta = beta*alfa;

alfa = alfa-1;

}

return beta;
}


int combinacion(int gama, int delta ){

int a = permutacion(delta);
int b = permutacion(gama);
int diff = delta - gama;
int c = permutacion(diff);

b = b * c;
a = a/b;

return a;

}

int arreglo(int epsilon, int zeta ){

int d = permutacion(zeta);
int diferencia = zeta - epsilon;
int e = permutacion(diferencia);

d = d/e;

return d;

}

int main(){

int teta = arreglo(3,4);

cout<<teta;

}


#include<iostream>
using namespace std;

int ind(int n, int i, int j){

return n*(i-1)+j-1;

}

class matr{

int dim;
double * a;

public:

matr();
matr(int d);  // единичная матрица      //разные конструкторый???
matr(int d, double * X);
matr(matr&X);
~matr();

void print();

// m+m, m-m, -m, m=m, m*m, k*m, m*v;
matr operator+(matr&r);
matr operator-(matr&r);
matr operator-();
matr &operator=(const matr&r);
matr operator*(matr&r);
friend matr operator*(double k, matr r);
//vect operator*(vect & r);

};

matr matr::operator*(matr&r){

matr tmp(r.dim);

for(int i = 1; i<=dim; i++){

    for(int j = 1; j <= dim; j++ ){

        tmp.a[ind(dim,i,j)] = NULL;
        for(int k=1;k<=dim;k++){

            tmp.a[ind(dim,i,j)] += a[ind(dim,i,k)]* r.a[ind(dim,k,j)];

            return tmp; 

        }

    }

}


}


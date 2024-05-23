#include <iostream>
using namespace std;


class vect {

public:
    int num;
    static int count;
    int dim;
    double *v;


    vect();
    vect(int d, double *x);
    
    vect(vect &x);
    ~vect();

    const vect operator+(vect &r) const;
    const friend vect operator-(vect l, vect r);
    friend vect operator*(vect l, int r);
    int operator*(vect &r);
    vect operator=(const vect &r);
    void print();
};

int vect::count = 0;
vect::vect() {
    count++;
    num = count;
    dim = 0;

    v = NULL;
}


vect::vect(int d, double *x) {
    count++; num = count;
    if (d > 0) {
        dim = d;
        v = new double[dim];
        for (int i = 0; i < dim; i++) {
            v[i] = x[i];
        }
    }

}
vect::vect(vect &x) {
    count++; num = count;
    dim = x.dim; // this -> dim = x.dim
    v = new double [dim];
    for (int i = 0; i < dim; i++) {
        v[i] = x.v[i];
    }
}
vect::~vect() {
    delete[] v;
}

///////////////////////////////

const vect vect::operator+(vect &r)const{
    vect tmp;
    tmp.dim = dim; //(r.dim, this -> dim)
    tmp.v = new double [dim];
    for (int i = 0; i < dim; i++) {
        tmp.v[i] = v[i] + r.v[i];
    }
    return tmp;
}
vect const operator-(vect l, vect r){
    vect tmp;
    tmp.dim = r.dim; //(r.dim, this -> dim)
    tmp.v = new double [r.dim];
    for (int i = 0; i < r.dim; i++) {
        tmp.v[i] = l.v[i] - r.v[i];
    }
    return tmp;
}
vect operator*(vect l, int r){
    vect tmp;
    tmp.dim = l.dim; //(r.dim, this -> dim)
    tmp.v = new double [l.dim];
    for (int i = 0; i < l.dim; i++) {
        tmp.v[i] = l.v[i] * r;
    }
    return tmp;
}


int vect::operator*(vect &r) {
    int tmp;
    for (int i = 0; i < dim; i++) {
        tmp += v[i] * r.v[i];
    }
    return tmp;
}

vect vect::operator=(const vect &r){

    delete[] v;
    dim = r.dim;
    v = new double [dim];

    for (int i = 0; i < dim; i++) {
        v[i] = r.v[i];
    }

    return *this;
}


void vect::print() {
    for (int i = 0; i < this->dim; i++) {
        std::cout << this->v[i] << " ";
    }
    std::cout << std::endl;
} 



//////////////////////////////////////////


int ind(int n, int i, int j){

return n*(i-1)+j-1;

}

class matr{

    int dim; double**a;

public: 
    matr();
    matr(matr&x);
    matr(int n); //единичная матрица
    matr(int n, double **x);
    ~matr();

    const matr operator+(matr&r)const;
    matr operator-(matr&r);
    matr operator-();
    matr operator*(matr&r);
    friend matr operator*(double k, matr &r);
    vect operator*(vect &r);
    matr  operator=(const matr &r);
    void print();
};

matr::matr() {
    dim = 0;
    a = NULL;
}

matr::matr(matr &x) {
    dim = x.dim;
    a = new double * [dim];
    for (int i = 0; i < dim; i++) {
        a[i] = new double [dim];
        for (int j = 0; j < dim; j++) {
            a[i][j] = x.a[i][j];
        }
    }
}

matr::matr(int n) {
    dim = n;
    a = NULL;
}

matr::matr(int n, double **x) {
    dim = n;
    a = new double * [dim];
    for (int i = 0; i < dim; i++) {
        a[i] = new double [dim];
        for (int j = 0; j < dim; j++) {
            a[i][j] = x[i][j];
        }
    }
}

matr::~matr() {
    for (int i = 0; i < dim; i++) {
        delete[] a[i];
    }
    delete[] a;
}


matr const matr::operator+(matr &r)const {
    matr tmp;
    tmp.dim = dim;
    tmp.a = new double * [dim];
    for (int i = 0; i < dim; i++) {
        tmp.a[i] = new double [dim];
        for (int j = 0; j < dim; j++) {
            tmp.a[i][j] = a[i][j] + r.a[i][j];
        }
    }
    return tmp;
}


matr matr::operator-(matr &r) {
    matr tmp;
    tmp.dim = dim;
    tmp.a = new double * [dim];
    for (int i = 0; i < dim; i++) {
        tmp.a[i] = new double [dim];
        for (int j = 0; j < dim; j++) {
            tmp.a[i][j] = a[i][j] - r.a[i][j];
        }
    }
    return tmp;
}

matr matr::operator-() {
    matr tmp;
    tmp.dim = dim;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            tmp.a[i][j] = -a[i][j];
        }
    }
    return tmp;
}

matr matr::operator*(matr &r) {
    matr tmp;
    tmp.dim = dim;
    tmp.a = new double * [dim];
    double p1 = 1;
    double p2 = 1;
    for (int i = 0; i < dim; i++) {
        tmp.a[i] = new double [dim];
        for (int j = 0; j < dim; j++) {
            for (int k1 = 0; k1 < dim; k1++) {
                p1 *= a[i][k1];
                p2 *= r.a[k1][j];
            }
            tmp.a[i][j] = p1 + p2;
            p1 = 1;
            p2 = 1;
        }
    }
    return tmp;
}

matr matr::operator=(const matr &r){
    dim = r.dim;
    a = new double * [dim];
    for (int i = 0; i < dim; i++) {
        a[i] = new double [dim];
        for (int j = 0; j < dim; j++) {
            a[i][j] = r.a[i][j];
        }
    }
    return *this;
}

matr operator*(double k, matr &r) {
    matr tmp;
    tmp.dim = r.dim;
    tmp.a = new double * [r.dim];
    for (int i = 0; i < r.dim; i++) {
        tmp.a[i] = new double [r.dim];
        for (int j = 0; j < r.dim; j++) {
            tmp.a[i][j] = r.a[i][j] * k;
        }
    }
    return tmp;
}

vect matr::operator*(vect &r) {
    vect tmp;
    tmp.dim = dim;
    tmp.v = new double [dim];
    for (int i = 0; i < dim; i++) {
        tmp.v[i] = 0;
        for (int j = 0; j < dim; j++) {
            tmp.v[i] += a[i][j] * r.v[j];
        }
    }
    return tmp;
}

void matr::print() {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
}



int main(){

double x1[] = {1,1,1,1};
double x2[] = {1,2,3,4};

vect v1(4,x1), v2(4,x2),v3;

v3 = v2 + v1;

v3.print();
v2.print();
v1.print();

std::cout<<endl;

v3 = v2 - v1;

v3.print();
v2.print();
v1.print();

std::cout<<endl;


int pato = v2 * v1;

std::cout<< pato<< endl;

std::cout<<endl;



v3 = v2 * 4;

v3.print();
v2.print();
v1.print();

std::cout<<endl;


v3 = v2 = v1;

v3.print();
v2.print();
v1.print();




 double **a = new double * [3];



 for (int i = 0; i < 3; i++) {

    a[i] = new double[3];

    for (int j = 0; j < 3; j++) {
            a[i][j] = 2*i + j+1;        
    }
        
}



std::cout<<endl<<endl<<endl<<endl;



matr m1(3,a);
matr m2(3,a);



std::cout<<"матрица а"<<endl;

m1.print();
std::cout<<endl;


matr m3;
matr m4;

m3 = m1 + m2;


m4 = m1 * m3;


std::cout<<"матрица m3"<<endl;
m3.print();

std::cout<<endl;

std::cout<<"матрица m4"<<endl;
m4.print();

std::cout<<endl;




std::cout<< vect::count<<endl;
return 0;

}
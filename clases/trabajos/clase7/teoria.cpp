#include <iostream>
using namespace std;
class vect {
private:
    int dim;
    double *v;
public:
    int num;
    static int count;

    vect();
    vect(int d, double *x);
    vect(vect &x);
    ~vect();

    const vect operator+(vect &r) const;
    friend vect operator-(vect l, vect r);
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

const vect vect::operator+(vect &r)const {
    vect tmp;
    tmp.dim = dim; //(r.dim, this -> dim)
    tmp.v = new double [dim];
    for (int i = 0; i < dim; i++) {
        tmp.v[i] = v[i] + r.v[i];
    }
    return tmp;
}
vect operator-(vect l, vect r) {
    vect tmp;
    tmp.dim = r.dim; //(r.dim, this -> dim)
    tmp.v = new double [r.dim];
    for (int i = 0; i < r.dim; i++) {
        tmp.v[i] = l.v[i] - r.v[i];
    }
    return tmp;
}
vect operator*(vect l, int r) {
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






int ind(int n, int i, int j){

return n*(i-1)+j-1;

}

class matr{

    int dim; double*a;
    public: matr();
    matr(matr&x);
    matr(int n); //единичная матрица
    matr(int n, double *x);
    ~matr();

    matr operator+(matr&r);
    matr operator-(matr&r);
    matr operator-();
    matr operator*(matr&r);
    friend matr operator*(double k, matr &r);
    vect operator*(vect &r);
    matr print();
};










int main(){

double x1[] = {1,1,1,1,1};
double x2[] = {1,2,3,4};

vect v1(5,x1), v2(4,x2),v3;

v3 = v1 + v2;

v3.print();
v2.print();
v1.print();

return 0;

}
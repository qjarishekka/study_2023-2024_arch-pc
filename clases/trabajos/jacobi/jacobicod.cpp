#include<iostream>
#include<math.h> //для использования функции abs
#include <cstdlib> // для использования функции srand
#include <ctime>    //для использования функции time

#define accuracy 0.001 //точность ответа
#define random 0    //случайность по времени

class matr; //объявление класса матрицы


//функция для замена нулей в функции matr::fill()
double corrector(double &a ){
    if (a == 0){    
        a = (rand() % 10000/100.0) - 50;
        corrector(a);
    }
return a;
}

//класс весткор
class vect {

public:

    int num;
    static int count;
    int dim;
    double *v;

    vect();
    vect(int d);
    vect(int d, double *x);
    
    vect(vect &x);
    ~vect();

    const vect operator+(vect &r) const;
    const friend vect operator-(vect l, vect r);
    friend vect operator*(vect l, int r);

    friend vect operator*(vect &r);

    int operator*(vect &r);
    vect operator=(const vect &r);

    vect jacobi(matr M, vect V, double a);
    
    void fill();
    void print();
};

int vect::count = 0;

vect::vect() {
    count++;
    num = count;
    dim = 0;

    v = NULL;
}
vect::vect(int d){
    count++;
    num = count;
    dim = d;
    v = new double [dim];

    for(int i = 0; i< dim ; i ++ ){

        v[i] = 0;

    }

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

//функция для заполнения векторов
void vect::fill(){

if(random){
std::srand(std::time(NULL));
}

v = new double [dim];


for(int i = 0; i<dim ; i++){

    v[i] = (rand()%10000 /100.0 ) - 50;

}

}

void vect::print() {
    for (int i = 0; i < this->dim; i++) {
        std::cout << this->v[i] << "\t";
    }
    std::cout << std::endl;
} 


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

int ind(int n, int i, int j){

return n*(i-1)+j-1;

}

//класс матрица
class matr{

protected:

    int dim; 
    double**a;

public: 
    
    matr();
    matr(matr&x);
    matr(int d); //единичная матрица
    matr(int n, double **x);
    ~matr();

    const matr operator+(matr&r)const;
    const matr operator+( vect &r )const;

    matr operator-(matr&r);
    matr operator-();
    matr operator*(matr&r);
    friend matr operator*(double k, matr &r);

    vect operator*(vect &r);
    matr operator=(const matr &r);

    friend vect vect::jacobi(matr M, vect V, double a);
    
    void print();
    void fill();

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
matr::matr(int d){
    dim = d;
    a = new double*[d];
    for(int i = 0; i< dim ; i++){

        a[i] = new double[dim];

    }

    for(int i = 0; i<dim ;i ++){

        for(int j = 0 ; j< dim ; j++){

            a[i][j] = 0;

        }

    }
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
            std::cout << a[i][j] << " \t";
        }
        std::cout << "\n";
    }
}

//заполняем матрицу
void matr::fill(){

if(random){
std::srand(std::time(NULL));
}


for(int i = 0; i < dim ; i++){
    
    for(int j = 0; j < dim ; j++){

        a[i][j] = (rand()%10000 /100.0 ) - 50;

    }

}

for(int i = 0; i < dim; i++){

    corrector(a[i][i]);

    a[i][i] = a[i][i] * 100;

}

}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////



// метод якоби(матрица, вектор, точность)
vect vect::jacobi(matr M, vect V, double a){

double suma = 0;    //сумма
double resta = 0;   //разность
double max = 0;     //мах


int flag = 1;
int index = 0;
int rep = 0;        //повторение

vect temp(V.dim);   
vect respuesta(V.dim);  //вектор ответа


//якоби алгоритм
do{

    //поиск самой большой разности значений векторов  X1[i] - X2[i]
    for(int i = 0; i < M.dim ; i++ ){

        if(temp.v[i] - respuesta.v[i] < temp.v[i+1] - respuesta.v[i+1]){

            index++;

        }
                  
    }

    //сумма всех значений матрицы кроме когда j = i;
    for(int i = 0; i < M.dim ; i ++){

        suma = 0;
        resta = 0;
        for(int j = 0; j < M.dim ; j++){
            if(i != j){
            suma += M.a[i][j] * temp.v[j];
            }
        }

        resta = V.v[i] - suma;
        temp.v[i] = resta/M.a[i][i];
    }

    //проверка точности ответа
    if( abs(temp.v[index] - respuesta.v[index]) <= accuracy){
        flag = 0;
    }

    //копия вектора для следующей интеракции
    for(int i = 0; i<V.dim ; i++){

        respuesta.v[i] = temp.v[i];

    }
    
    rep++;

    std::cout<<rep<<std::endl;

}while(flag);

std::cout<<rep<<std::endl;

/*
for(int i =0 ; i < V.dim ; i++ ){

    std::cout<<respuesta.v[i]<<"\t";

}
*/

return respuesta;
}





int main (){

//Aij = (rand()%10000/100.0) - 50;
// Aij != 0;
// Aii = Aii * 100;



/*
double **a;
double *c;
a = new double*[4];
c = new double[3];


double b[3][3] = {{25, -0.9, -0.3} , {3.7, -7.3, -0.1} , {0.7, 0.1, -8.2}};
double d[3] = { 20.2, -18.9 , -56 };

for(int i = 0; i < 3; i++){

    a[i] = new double[4];

    for(int j = 0 ; j < 3 ; j++){

        a[i][j] = b[i][j];

    }

}

for(int i = 0; i< 3 ; i++){

    c[i] = d[i];

}
*/

int n;

std::cout<<"введите размер матрицы"<<std::endl;

std::cin>> n;
std::cout<<std::endl;

matr A(n);
vect B(n);

vect R;

A.fill();
A.print();

std::cout<<std::endl;

B.fill();
B.print();

std::cout<<std::endl;



R = R.jacobi(A,B,accuracy);

std::cout<<"ответ: ";
R.print();

std::cout<<std::endl;

return 0;
}
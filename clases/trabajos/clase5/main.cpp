#include <iostream>

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

    vect operator+(vect &r);
    vect operator-();
    friend vect operator-(vect l, vect r);
    friend vect operator*(vect l, int r);
    int operator*(vect &r);
    vect operator=(vect &r);
    void print();
};

int vect::count = 0;
vect::vect() {
    count++;
    num = count;
    dim = 0;
    v = NULL;
    std::cout << "Создан вектор\nНомер вектора: " << num << "\nВсего векторов: " << count;
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
    std::cout << "Создан вектор\nНомер вектора: " << num << "\nВсего векторов: " << count;
}
vect::vect(vect &x) {
    count++; num = count;
    dim = x.dim; // this -> dim = x.dim
    v = new double [dim];
    for (int i = 0; i < dim; i++) {
        v[i] = x.v[i];
    }
    std::cout << "Создан вектор\nНомер вектора: " << num << "\nВсего векторов: " << count;
}
vect::~vect() {
    count--;
    std::cout << "Уничтожен вектор\nНомер вектора: " << num << "\nВсего векторов: " << count;
    delete[] v;
}
vect vect::operator+(vect &r) {
    vect tmp;
    tmp.dim = dim; //(r.dim, this -> dim)
    tmp.v = new double [dim];
    for (int i = 0; i < dim; i++) {
        tmp.v[i] = v[i] + r.v[i];
    }
    std::cout << "Произошло сложение векторов с номерами " << num << " и"  << r.num;
    return tmp;
}
vect operator-(vect l, vect r) {
    vect tmp;
    tmp.dim = r.dim; //(r.dim, this -> dim)
    tmp.v = new double [r.dim];
    for (int i = 0; i < r.dim; i++) {
        tmp.v[i] = l.v[i] - r.v[i];
    }
    std::cout << "Произошло вычитание векторов с номерами " << l.num << " и"  << r.num;
    return tmp;
}
vect vect::operator-() {
    vect tmp;
    tmp.dim = dim;
    tmp.v = new double [dim];
    for (int i = 0; i < dim; i++) {
        tmp.v[i] = -v[i];
    }
    std::cout << "Произошло унарное вычитание вектора с номером " << num;
    return tmp;
}
vect operator*(vect l, int r) {
    vect tmp;
    tmp.dim = l.dim; //(r.dim, this -> dim)
    tmp.v = new double [l.dim];
    for (int i = 0; i < l.dim; i++) {
        tmp.v[i] = l.v[i] * r;
    }
    std::cout << "Произошло умножение числа на вектор с номером " << l.num;
    return tmp;
}
int vect::operator*(vect &r) {
    int tmp;
    for (int i = 0; i < dim; i++) {
        tmp += v[i] * r.v[i];
    }
    std::cout << "Произошло умножение векторов с номерами " << num << " и"  << r.num;
    return tmp;
}

vect vect::operator=(vect &r) {
    for (int i = 0; i < dim; i++) {
        v[i] = r.v[i];
    }
    std::cout << "Произошло присваивание векторов с номерами " << num << " и"  << r.num;
    return *this;
}
void vect::print() {
    for (int i = 0; i < this->dim; i++) {
        std::cout << this->v[i] << " ";
    }
    std::cout << std::endl;
}


int ind (int n, int c, int j);
class matr {
    int dim; double **a;
public:
    matr();
    matr(matr &x);
    matr(int n);
    matr(int n, double **x);
    ~matr();

    matr operator+(matr &r);
    matr operator-(matr &r);
    matr operator-();
    matr operator*(matr &r);
    friend matr operator*(double k, matr &r);
    vect operator*(vect &r);
    matr operator=(matr &r);
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

matr matr::operator+(matr &r) {
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

matr matr::operator=(matr &r) {
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

int main() {
    std::cout << "Hello, World!" << std::endl;
    double **a = new double * [3];
    for (int i = 0; i < 3; i++) {
        a[i] = new double[3];
        for (int j = 0; j < 3; j++) {
            std::cin >> a[i][j];
        }
    }
    matr *m1 = new matr(3, a);
    matr *m2 = new matr(3, a);
    matr m3 = *m1 + *m2;
    matr m4 = *m1 * m3;
    m1->print();
    m3.print();
    m4.print();

    return 0;
}

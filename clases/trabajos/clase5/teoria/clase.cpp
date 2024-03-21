/*#include <iostream>


class vect{
private:
    int dim; //dimenciones
    double *v; //компоненты
public:
    int num; //номер
    static int count; //количество векторов


vect();
vect(int d, double *X);
vect(vect &X);
~vect();
vect operator+(vect &r); //r
friend vect operator-(vect e, vect r)//r
vect operator = (vect&r)
void print();
}


int vect::count = 0;

vect::vect(){
count ++; num = count;
dim = 0; v = NULL;

vect::vect(int d,double*X){

count++; num = count;
dim = d;
v = new double[dim];
for(int i =0; i<dim;i++){
    v[i] = X[i];
    }
}

vect::vect(vect&X){

count++; num = count;
dim = X.dim;
v = new double[dim];
for(int i = 0; i<dim;i++){
    v[i] = X.v[i];
}
}

vect ::~vect(){
delete[]v;
}


vect vect::operator+(vect r){

vect tmp;
tmp.dim = dim; //*(v.dim,this->dim)
tmp.v=new double[dim];
for(int i=0;i<dim;i++)tmp.v[i]=v[i]+r.v[i];
return tmp;
}

vect operator-(vect e,vect r){

    vect tmp;
    tmp.dim = e.dim;
    tmp.v = new double[tmp.dim];
    for(int i =0; i<e.dim;i++) tmp.v[i] = e.v[i]-r.v[i];
    return tmp;

}

vect vect :: operator=(vect&r){

for(int i = 0; i < dim,i++){
    v[i]= r.v[i];

return *this;
}
}

//tarea: 1)павловская   2) K*V = V      3) V*V= k       4) -V
 
}
*/
#include <iostream>
using namespace std;


class complex{
public:
    double re; double im;
    complex(){}
    complex::complex(double r, double i){
        re = r; im = i;
    };


complex(complex & x){
re = x.re; im = x.im;
}

~complex(){
cout<< "удаление комда гисля";
}


void set(double x, double y){
re = x; im = y; return;
}

complex sum(complex x, complex y){
complex tmp;
tmp.re = x.re + y.re;
tmp.im = x.im + y.im;
return tmp;
};

complex operator- (complex r){
complex tmp;
tmp.re = re - r.re;
tmp.im = im - r.im;
return tmp;
}
};

int main(){

    complex x,y(3.5),z;

    x.set(2.5,7.5);
    z = x-y;
    z = sum(x,y);
cout<<"z = "<< z.re << "+i"<<z.im;
return NULL;

}
#include<iostream>
#include<math.h>
#define PI 3.14159265358979323846


using namespace std;

double AnguloDeInclinacion(double x, double y,double dx, double dy){

double pendiente = (dy-y) / (dx-x);

cout<<pendiente<<endl;

double grados = (atan(pendiente)*180)/PI ;


return grados;
}


int main(){



cout<< AnguloDeInclinacion(1,1,2,2)<<endl;


return 0;

}
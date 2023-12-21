#include <stdio.h>
#include <math.h>

int main(){

int a,b;
float mediageometricacubos = 0;
float mediageometricamodulos = 0;
int moduloA,moduloB;

printf("эта программа вычисляет среднее арифметическое кубов этих чисел и среднее геометрическое модулей этих чисел\n");

scanf("%d %d",&a,&b);

mediageometricacubos = (pow(a,2) + pow(b,2))/2;

if(a>0){

    moduloA = a;

}else{

    moduloA = a*(-1);

}

if(b>0){

    moduloB = b;

}else{

    moduloB = b*(-1);

}

mediageometricamodulos = pow(moduloA*moduloB,1/2);

printf("среднее арифметическое кубов равно: %f \nсреднее геометрическое модулей равно: %f",mediageometricacubos,mediageometricamodulos);


}
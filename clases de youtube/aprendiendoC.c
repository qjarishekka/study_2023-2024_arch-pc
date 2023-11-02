#include <stdio.h>


int main(){
//constantes:
        //#define PI 3.14;  (#define NOMBRE valor;)
// variables:
        //float sueldo = 15.456; (tipoDato Nombre = valor;)
    int edad = 43;
    int edad2 = 15;
    int sueldo = 0;


    printf("hola mundo \n "); 
    printf("La primera edad es:%d \n la segunda edad es:%d\n",edad2,edad);
    
    sueldo = edad + edad2;
    printf("%d",sueldo);
    return 0;

}
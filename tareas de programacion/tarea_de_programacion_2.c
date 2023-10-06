#include <stdio.h>
#include <math.h>


int main()
{
    int area_circulo ,area_cuadrado;
    float lado;
    float radio;
    printf("введите площадь круга:\n");

    scanf("%d",&area_circulo);

    printf("введите площадь квадрата:\n");

    scanf("%d",&area_cuadrado);

    lado = pow(area_cuadrado,0.5);
    radio = pow(area_circulo/3.14,0.5);
    
    

// si el radio del circulo es menor o igual a la mitad del lado del cuadrado entonces el circulo entra en el cuadrado

    if(radio <= lado/2) {

        printf("круг уместится в квадрате\n");
    }
        else {
            printf("круг не уместится в квадрате\n");
        }



}
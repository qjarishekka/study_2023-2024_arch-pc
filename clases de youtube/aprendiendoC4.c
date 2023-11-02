#include <stdio.h>
int main()
{
    float examen1, examen2;
    float notafinal;

    printf("ingrese la nota del primer examen:");
    scanf("%f",&examen1);
    printf("ingrese la nota del segudno examen:");
    scanf("%f",&examen2);

    notafinal = (examen1+examen2)/2;
    printf("la nota final es: %.2f",notafinal); // %.2f los numeros seguidos del punto indica cuantos decimales quieres mostrar


return 0;
}
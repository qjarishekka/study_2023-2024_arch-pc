// crea un tablero de ajedres

#include <stdio.h>

int main()
{
    float grupo[8];
    int i = 0;

    for(i=0;i<=8;i++) {
        grupo[i] = 0;

    }


    for (i=0;i<=8;i++){
        printf("le valor del arreglo en la fila %d es: %d",i, grupo[i]);
    }

}
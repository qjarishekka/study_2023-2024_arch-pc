// crea un tablero de ajedres

#include <stdio.h>

int main()
{
    int grupo[7];
    int i = 0;
    char ficha[5];
     printf("%d\n",grupo[8]);

    for(i=0;i<=6;i++){
        grupo[i] = 0;

    }


    for (i=1;i<=7;i++){

        printf("le valor del arreglo en la fila %d es: %d\n", i , grupo[i-1]);
    
    }
    
    scanf("%s",&ficha);

    printf("%s",ficha);
    
    

}
#include <stdio.h>

int main(){

    int matriz[8][8];
    int i = 0;
    int x = 0;
    int y = 0;

    for(y=0;y<=7;y++){      //poner todo los valores a 0

         for(x=0;x<=7;x++){
            matriz[y][x] = 0;
        }

    }
    
     
        
    for(y=0;y<=7;y++){

         for(x=0;x<=7;x++){

             printf("%d  ", matriz[y][x]);

        }
        printf("\n");
   }

}
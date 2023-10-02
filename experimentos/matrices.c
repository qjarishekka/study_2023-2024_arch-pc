#include <stdio.h>
#include <math.h>

int main(){


    //tablero de juego
    char matriz[8][8];

    //fin del juego
    int jaque_mate = 0;

    //cambiar el tablero
    char cuadrado_claro = 'O';      
    char cuadrado_oscuro = '0';
    //
    
    //fichas de juego
    char peon_negro = 'p';
    char caballo_negro = 'c';
    char alfil_negro = 'a';
    char torre_negra = 't';
    char dama_negra = 'r';
    char rey_negro = 'k';


    char peon_blanco = 'P';
    char caballo_blanco = 'C';
    char alfil_blanco = 'A';
    char torre_blanca = 'T';
    char dama_blanca = 'R';
    char rey_blanco = 'K';

    //

    int i = 0;
    int x = 0;
    int y = 0;

    for(y=0;y<=7;y++){      //darle valores iniciales a las casillas para crear un tablero

         for(x=0;x<=7;x++){
            
            if(pow(-1,x+y)>0){

                matriz[y][x] = cuadrado_oscuro;

            }
                else{

                   matriz[y][x] = cuadrado_claro;

                }
            
            
            
        }

    }
    //
    
    for(i=0;i<=1;i++){ //este bucle es temporal hasta que pueda hacer la parte del codigo que la orden jaque mate


        printf("\n\n\n\n\n");

                for(y=0;y<=7;y++){      //imprimir el tablero de ajedrez

                    for(x=0;x<=7;x++){

                        printf("%c  ", matriz[y][x]);

                        }
                        printf("\n");
                    }
                     //

                            
                            //imprimir posicion inicial

                                    //impresion de peones
                                
                            for(x=0;x<=7;x++){

                                matriz[1][x] = peon_negro;
                                matriz[6][x] = peon_blanco;

                            }

                                    //impresion de torres
                                    

            

    }









}
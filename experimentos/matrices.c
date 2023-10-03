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
            
            if(pow(-1,x+y-1)>0){

                matriz[y][x] = cuadrado_oscuro;

            }
                else{

                   matriz[y][x] = cuadrado_claro;

                }
            
            
            
        }

    }
    //
    
    
    //bucle de juego
    for(i=0;i<=1;i++){ //este bucle es temporal hasta que pueda hacer la parte del codigo que la orden jaque mate

        

        printf("\n\n\n\n\n");

                
                //imprimir el tablero de ajedrez
                for(y=0;y<=7;y++){      

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
                                    //

                            }

                                    //impresion de torres
                            
                            matriz[0][0] = torre_negra;
                            matriz[0][7] = torre_negra;
                            matriz[7][0] = torre_blanca;
                            matriz[7][7] = torre_blanca;
                                    //
                                    
                                    
                                    //impresion de caballos
                    
                            matriz[0][1] = caballo_negro;
                            matriz[0][6] = caballo_negro;
                            matriz[7][1] = caballo_blanco;
                            matriz[7][6] = caballo_blanco;
                                    //

                                    
                                    //impresion de alfiles
                            
                            matriz[0][2] = alfil_negro;
                            matriz[0][5] = alfil_negro;
                            matriz[7][2] = alfil_blanco;
                            matriz[7][5] = alfil_blanco;
                                    //
                                    
                                    
                                    //impresion de reynas
                           
                            matriz[0][3] = dama_negra;
                            matriz[7][3] = dama_blanca;
                                    //


                                    //impresion de reyes
                            matriz[0][4] = rey_negro;
                            matriz[7][4] = rey_blanco;
                                    //
                                
                                
                             //



    }
    //







}
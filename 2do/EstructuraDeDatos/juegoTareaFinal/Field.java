package juegoTareaFinal;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.util.Random;

import javax.swing.JComponent;
import javax.swing.JLabel;

public class Field extends JComponent{
    
    char field[][];
    Point playerPosition;
    JLabel asteroide;




    public Field(Player player , MainFrame mainFrame){

        field = new char[ mainFrame.getHeight()/(mainFrame.getHeight()*10/100)  ][ mainFrame.getWidth()/(mainFrame.getHeight()*10/100) ];
        //field = new char[10][10];
        genField();
        
        /* for(int i = 0 ; i < field.length; i++){
            for(int j = 0 ; j < field[i].length ; j++){
                if(genRandom.nextInt(100) < 50 ){
                    field[i][j] = '_';
                }else{
                    field[i][j] = '0';
                }
            }
        } */

        printFieldInConsole();

    }

    public void genField(){
        Random rng = new Random();
        
        for(int i = 0 ; i < field.length; i++){
            
            for(int j = 0 ; j < field[i].length ; j++){

                if(j % 2 == 0){
                    if(i %2 == 0)
                        field[i][j] = '0';
                    else{
                        field[i][j] = '_';
                        if(rng.nextInt(100) < 15)
                            field[i][j]  = '0';
                    }
                        
                        
                }else{
                    field[i][j] = '_';
                    if(rng.nextInt(100) < 15)
                            field[i][j]  = '0';
                }
                
            }
        }
    }


    

    private void printFieldInConsole(){
        for(int i = 0 ; i < field.length ; i++){
            for(int j = 0 ; j < field[i].length ; j++){
                //String string = new String();
                //string = string + field[i][j]; 
                System.out.print(field[i][j] + " ");
            }
            System.out.println();
        }
    }




}

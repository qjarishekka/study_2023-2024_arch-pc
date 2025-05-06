package juegoTareaFinal;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.util.ArrayList;
import java.util.Random;

import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.plaf.metal.MetalInternalFrameTitlePane;

public class Field extends JLabel {
    //char field[][];
    
    Point playerPosition;
    JLabel asteroide;
    public Meteorite meteoritesField[][];
    int screenHeight;
    int screenWidth;



    public ArrayList<Point> path =  new ArrayList<>(1);
    int [][]matrix;

    Point start = new Point(0, 0), finish = new Point(0, 0); 

    




    public Field(Player player , MainFrame mainFrame){
        screenHeight = mainFrame.getHeight();
        screenWidth = mainFrame.getWidth();
        
        setBounds(0 , 0 , screenWidth,screenHeight);
        setFocusable(false);
        setOpaque(true);
        setBackground(new Color(255, 255, 255 ,0));
        //field = new char[ mainFrame.getHeight()/(mainFrame.getHeight()*10/100)  ][ mainFrame.getWidth()/(mainFrame.getHeight()*10/100) ];
        meteoritesField = new Meteorite[ mainFrame.getHeight()/(mainFrame.getHeight()*10/100)  ][ mainFrame.getWidth()/(mainFrame.getHeight()*10/100) ];
        initMeteoritesMatrix(mainFrame.getHeight());
        genField();
        printFieldInConsole();

        matrix = new int[meteoritesField.length][meteoritesField[0].length];

    }






    public void genField(){
        Random rng = new Random();
        
        for(int i = 0 ; i < meteoritesField.length; i++){
            
            for(int j = 0 ; j < meteoritesField[i].length ; j++){

                if(j % 2 == 0){
                    if(i %2 == 0){
                        meteoritesField[i][j].value = '0';
                        generateMeteorite(i, j);
                    }else{
                        if(rng.nextInt(100) < 15 && i!= 0){
                            meteoritesField[i][j].value  = '0';
                            generateMeteorite(i, j);
                        }
                        
                    }
                        
                        
                }else{
                    
                    if(rng.nextInt(100) < 15){
                        meteoritesField[i][j].value  = '0';
                        generateMeteorite(i, j);
                    }
                        
                }
                
            }
        }

        meteoritesField[0][1].value = '_';
        remove(meteoritesField[0][1]);
    }

    private void initMeteoritesMatrix(int size){
        for(int i = 0; i < meteoritesField.length ; i++){
            for(int j = 0 ; j < meteoritesField[i].length ; j++){
                meteoritesField[i][j] = new Meteorite(size);
            }
        }
    }

    public void generateMeteorite(int i , int j){
        int meteoriteSize = (int)(meteoritesField[i][j].getBounds().getHeight());
        meteoritesField[i][j].setLocation((int)(j * meteoriteSize) , (int)(i * meteoriteSize));
        //System.out.println(screenHeight/meteoriteSize);
        add(meteoritesField[i][j]);
    }

    

    private void printFieldInConsole(){
        for(int i = 0 ; i < meteoritesField.length ; i++){
            for(int j = 0 ; j < meteoritesField[i].length ; j++){
                //String string = new String();
                //string = string + field[i][j]; 
                System.out.print(meteoritesField[i][j].value + " ");
            }
            System.out.println();
        }
    }

    boolean checkOutRange(int x ,int y ){

        return y < 0 || y >= matrix.length || x < 0 || x >= matrix[y].length;
    }

    boolean checkNeighbor(int i , int j , int dy , int dx){
        if(checkOutRange(j + dx , i + dy)){
            
            return false;
        }
            
        
        if (  matrix[i + dy][j + dx] >= 0 && ( matrix[i][j] == -1  ||  matrix[i][j] > matrix[i + dy][j + dx] + 1 )    ) {
            
            matrix[i][j] = matrix[i + dy][j + dx] + 1; 
            //sleep(1);
            return true;
        } 
        return false;
    }






    public void pathfinder(){

        path = new ArrayList<>(20);
        

        for(int i = 0; i < matrix.length ; i++){
            for(int j =0 ; j < matrix[i].length; j++){
                matrix[i][j] = meteoritesField[i][j].value == '0' ? -2 : -1;
            }
        }

        Point []neighbors = new Point[]{
            new Point(0 , 1),
            new Point(0 , -1),
            new Point(1 , 0),
            new Point(-1 , 0),

        };

        

        matrix[start.y][start.x] = 0;
        boolean fl = true;
        while(fl && matrix[finish.y][finish.x] < 0){
            fl = false;
            for(int i = 0 ; i < matrix.length ; i++){
                for(int j = 0 ; j < matrix[i].length ; j++){
                    for(Point neighbor : neighbors){
                        fl = fl || checkNeighbor(i, j, neighbor.y, neighbor.x);
                    }
                }
            }
        }
        
        //System.out.println("antes");

        if(matrix[finish.y][finish.x] < 0){
            //searching = false;
            path.add(new Point(start.x, start.y));
            return;
        }

        
        

        Point current = new Point(finish.x, finish.y);
        while(current.x != start.x || current.y != start.y){ 
            if(current.x > 0 && matrix[current.y][current.x - 1] >= 0 && 
                    matrix[current.y][current.x - 1] < matrix[current.y][current.x]){ 
                current.x--; 

            }else if(current.x < matrix[0].length - 1 && matrix[current.y][current.x + 1] >= 0 && 
                    matrix[current.y][current.x + 1] < matrix[current.y][current.x]){ 
                current.x++; 

            }else if(current.y > 0 && matrix[current.y - 1][current.x] >= 0 && 
                    matrix[current.y - 1][current.x] < matrix[current.y][current.x]){ 
                current.y--; 

            }else if(current.y < matrix.length - 1 && matrix[current.y + 1][current.x] >= 0 &&
                    matrix[current.y + 1][current.x] < matrix[current.y][current.x]){ 
                current.y++; 

            } 

            //System.out.println("antes");
            path.add(new Point(current.x, current.y)); 
            //System.out.println("despues");

            
        }

        //path.remove(current);

    } 

    private Point getPositionInField(Point object){
        return new Point(object.x/meteoritesField[0][0].meteoriteSize , object.y/ meteoritesField[0][0].meteoriteSize);
    }

    public void setStartAndFinish(Point enemy , Point player){
        start = getPositionInField(enemy);
        finish = getPositionInField(player);

    }




    







}

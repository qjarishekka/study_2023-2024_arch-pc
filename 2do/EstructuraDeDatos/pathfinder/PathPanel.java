package pathfinder;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.Random;

import javax.swing.JComponent;

public class PathPanel extends JComponent implements MouseListener{
    static final int CELL_SIZE = 30;
    char [][] field;
    Point start = new Point(-1,-1) , finish = new Point(-1, -1);
    

    class Path{
        ArrayList<Point> steps;
        Path(){
            steps = new ArrayList<>(20);


        }
    }


    Path currenPath = null;


    PathPanel(int w, int h){

        setSize(w,h);
        field = new char[w/CELL_SIZE][h/CELL_SIZE];
        gen();
        addMouseListener(this);


    }

    void findPath(){
        
    }


    void gen(){
        Random rng = new Random();
        for(int i = 0 ; i < field.length; i++)
            for(int j =0 ; j < field[i].length ; j++){
                int rnd = rng.nextInt(100);
                if(rnd < 70){
                    field[i][j] = '_';

                }else{
                    field[i][j] = '0';

                }

            }
    }

    Color getColor(int i, int j){
        if(start.x == j && start.y == i )
            return Color.GREEN;
            if(finish.x == j && finish.y == i )
            return Color.red;

        switch (field[i][j]){
            case '_' : return Color.white;
            case '0' : return Color.gray;
            default : return Color.black;
        }
        //return Color.gray;
    }

    @Override
    public void paint(Graphics g){
       /*  g.setColor(Color.WHITE);
        g.fillRect(0, 0, getWidth(), getHeight()); */

        for(int i = 0 ; i < field.length; i++)
            for(int j =0 ; j < field[i].length ; j++){
                g.setColor(getColor(i, j));
                g.fillRect(j*CELL_SIZE , i*CELL_SIZE, CELL_SIZE ,CELL_SIZE );
            }
        
        
    }


    @Override
    public void mousePressed(MouseEvent e) {
        int I = e.getY() / CELL_SIZE;
        int J = e.getX() / CELL_SIZE;
        if(e.getButton() == MouseEvent.BUTTON1)
            start = new Point(J,I);
        else 
            finish = new Point(J, I);

        repaint();
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        
    }


    @Override
    public void mouseEntered(MouseEvent e) {
        
    }


    @Override
    public void mouseExited(MouseEvent e) {
        
    }


    


    @Override
    public void mouseReleased(MouseEvent e) {
        
    }
}

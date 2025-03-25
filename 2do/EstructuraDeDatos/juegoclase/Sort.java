package juegoclase;

import java.util.Random;

import javax.swing.JLabel;

import java.awt.Color;
import java.awt.Graphics;

public class Sort extends JLabel implements Runnable {
    int N;
    int [] array;
    Sort(int N){
        this.N = N;
        array = new int [N];

    }


    void gen(){
        Random random = new Random();
        for(int i = 0; i < N ; i++){
            array[i] = random.nextInt(100);
        }
    }


    @Override
    public void paint(Graphics g){
        g.setColor(Color.white);
        g.fillRect(0, 0, 10, 10);
        g.setColor(Color.gray);
        for(int i = 0; i < N ; i++){
            g.fillRect(i*10, 0, 10, array[i]);
        }
        ///repaint();
    }

    void bubble(){
        new Thread(this).start();
    }


    @Override
    public void run() {
        for(int i = 0  ; i < N ; i++ ){
            for(int j = 0 ; j < N ; j ++){
                if(array[j] > array[j+1]){
                    int swap = array[j];
                    array[j] = array[j+1];
                    array[j+1] = swap;
                }
            }
            repaint();
            try {
                Thread.sleep(5);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    }


}

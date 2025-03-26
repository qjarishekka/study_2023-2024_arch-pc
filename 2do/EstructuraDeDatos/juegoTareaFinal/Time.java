package juegoTareaFinal;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Time implements ActionListener {

    long time = 0;
    


    @Override
    public void actionPerformed(ActionEvent e) {
        time++;
       // System.out.println(System.nanoTime()/1e9);
        

    }

    
}

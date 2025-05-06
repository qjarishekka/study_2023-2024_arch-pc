package juegoTarea;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;

public class ExitButtonListener implements ActionListener{

    MainFrame proxy;

    ExitButtonListener(MainFrame proxy){
        this.proxy = proxy;

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        System.gc();
        proxy.dispose();
        System.exit(128);
    }
    
}

package JuegoTarea;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;

public class ExitButtonListener implements ActionListener{

    Main proxy;

    ExitButtonListener(Main proxy){
        this.proxy = proxy;

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        proxy.dispose();
    }
    
}

package JuegoTarea;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PlaybuttonListener implements ActionListener{

    Main main;

    PlaybuttonListener(Main main ){

        this.main = main;


    } 

    @Override
    public void actionPerformed(ActionEvent e) {
        
        main.sceneManager();

    }


    
}

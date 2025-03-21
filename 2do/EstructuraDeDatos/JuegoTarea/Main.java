package JuegoTarea;
import java.awt.*;
import javax.swing.*;


public class Main extends JFrame {

    boolean playing = false;

    
    

    Main(){
        
        super("MyGame");

        Toolkit t = Toolkit.getDefaultToolkit();
        double screenSize[] = new double [2];
        screenSize[0] = t.getScreenSize().getWidth();
        screenSize[1] = t.getScreenSize().getHeight();


        
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize((int)screenSize[0],(int)screenSize[1]);
        setLayout(null);
        //setUndecorated(true);

        setVisible(true);

    }

    public void sceneManager(){
        
    }

    


    static Main proxy;
    public static void main(String[] args){
        
        proxy = new Main();        
        
        

       
    }

}

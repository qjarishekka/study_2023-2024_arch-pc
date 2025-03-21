package JuegoTarea;
import java.awt.*;
import java.util.Observer;
import java.lang.Exception;

import javax.swing.*;

import juegoclase.RotImage;


public class Main extends JFrame {


    public boolean Start = false;
    int screenSize[] = new int [2];
    static Main proxy;
    
    

    Main(){
        
        super("MyGame");

        Toolkit t = Toolkit.getDefaultToolkit();
        
        screenSize[0] = (int)t.getScreenSize().getWidth();
        screenSize[1] = (int)t.getScreenSize().getHeight();        
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize((int)screenSize[0],(int)screenSize[1]);
        setLayout(null);
        //setUndecorated(true);

        

        setVisible(true);

    }

    public void sceneManager(){

        if(!Start){
            scene1();
            Start = true;
            System.out.println("escena1");
        }else{
            scene2();
            Start= false;
            System.out.println("escena2");

        }
        
        


    }

    public void scene1(){

        Image backGroundImage  = new ImageIcon("src//backGround.png").getImage();
        JLabel backGround = new JLabel(new ImageIcon(backGroundImage.getScaledInstance((int)screenSize[0], (int)screenSize[1],0 )));
        


        backGround.setBounds(0 ,0 , (int)screenSize[0], (int)screenSize[1]);
        
        JButton playButton = new JButton();
        int playButtonWidth = screenSize[0] * 30 / 100;
        int playButtonHeight = screenSize[1] * 20 / 100;
        playButton.setBounds( (screenSize[0]/2) - (playButtonWidth/2)  ,(screenSize[1]/2) - (playButtonHeight/2),playButtonWidth,playButtonHeight);
        Image playImage = new ImageIcon("src//play.png").getImage();
        JLabel play = new JLabel(new ImageIcon(playImage.getScaledInstance(playButtonWidth, playButtonHeight, 0)));
        
        PlaybuttonListener playButtonListener = new PlaybuttonListener(proxy);
        playButton.addActionListener(playButtonListener);
        

        JButton exitButton = new JButton();
        int exitButtonWidth = screenSize[0] * 25 / 100;
        int exitButtonHeight = screenSize[1] * 15 / 100;
        exitButton.setBounds( (screenSize[0]/2) - (exitButtonWidth/2)  ,  screenSize[1] - exitButtonHeight*5/2 , exitButtonWidth, exitButtonHeight);
        ExitButtonListener exitButtonListener = new ExitButtonListener(proxy);
        exitButton.addActionListener(exitButtonListener);





        add(playButton);
        playButton.setIcon(play.getIcon());

        add(exitButton);
        
        
        add(backGround);
        repaint();
        
        
        
        

    }

    public void scene2(){

        getContentPane().removeAll();

        Image backGroundImage  = new ImageIcon("src//backGround.png").getImage();
        JLabel backGround = new JLabel(new ImageIcon(backGroundImage.getScaledInstance((int)screenSize[0], (int)screenSize[1],0 )));
        backGround.setBounds(0 ,0 , (int)screenSize[0], (int)screenSize[1]);
        



        
        proxy.add(backGround);


        repaint();


    }

    


    
    public static void main(String[] args){

        proxy = new Main();
        proxy.sceneManager();

        

        
    }

}

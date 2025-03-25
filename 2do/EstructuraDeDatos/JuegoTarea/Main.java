package JuegoTarea;
import java.awt.*;
import java.awt.event.KeyListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.Observer;
import java.util.stream.Stream;
import java.lang.Exception;

import javax.swing.*;

import JuegoTarea.src.fonts.CustomFonts;
import juegoclase.RotImage;


public class Main extends JFrame{


    public boolean Start = false;
    //int screenSize[] = new int [2];
    static Main proxy; 
    

    BufferedReader bufferedReader;
    long linesCounter;
    File file;
    FileReader fileReader;
    Scores scores = new Scores();

    CustomFonts customFonts = new CustomFonts();
    Player player;



    Main(){
        
        super("MyGame");

        Toolkit t = Toolkit.getDefaultToolkit();
            
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize((int)t.getScreenSize().getWidth(),(int)t.getScreenSize().getHeight());
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

        //getContentPane().removeAll();

        Image backGroundImage  = new ImageIcon("src//backGround.png").getImage();
        JLabel backGround = new JLabel(new ImageIcon(backGroundImage.getScaledInstance((int)getWidth(), (int)getHeight(),0 )));
        


        backGround.setBounds(getBounds());
        
        JButton playButton = new JButton();
        int playButtonWidth = getWidth() * 30 / 100;
        int playButtonHeight = getHeight() * 20 / 100;
        playButton.setBounds( (getWidth()/2) - (playButtonWidth/2)  ,(getHeight()/2) - (playButtonHeight/2),playButtonWidth,playButtonHeight);
        Image playImage = new ImageIcon("src//play.png").getImage();
        JLabel play = new JLabel(new ImageIcon(playImage.getScaledInstance(playButtonWidth, playButtonHeight, 0)));
        
        PlaybuttonListener playButtonListener = new PlaybuttonListener(proxy);
        playButton.addActionListener(playButtonListener);
        

        JButton exitButton = new JButton();
        int exitButtonWidth = getWidth() * 25 / 100;
        int exitButtonHeight = getHeight() * 15 / 100;
        exitButton.setBounds( (getWidth()/2) - (exitButtonWidth/2)  ,  getHeight() - exitButtonHeight*5/2 , exitButtonWidth, exitButtonHeight);
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
        JLabel backGround = new JLabel(new ImageIcon(backGroundImage.getScaledInstance((int)getWidth(), (int)getHeight(),0 )));
        backGround.setBounds(0 ,0 , (int)getWidth(), (int)getHeight());
        
        JLabel points = new JLabel();
        points.setBounds(10,10,getWidth()*30/100 , getHeight()*20/100);
        points.setText("Record: "+ scores.maxScore[0] + " by " + scores.maxScore[1]);
        points.setFont(customFonts.font);
        points.setForeground(Color.green);
        points.setBackground(Color.BLACK);
        //points.setOpaque(true);

        JLabel currentPoints = new JLabel();
        currentPoints.setBounds(getWidth()/2 - getWidth()*7/100, 10, getWidth()*15/100, getHeight()*15/100);
        currentPoints.setText("Score: 000");
        currentPoints.setFont(customFonts.font);
        currentPoints.setForeground(Color.green);
        currentPoints.setBackground(Color.WHITE);
        //currentPoints.setOpaque(true);

        
        player = new Player(proxy);
        GameManager gameManager = new GameManager(this);
        Thread thread = new Thread(gameManager);
        thread.start();

        Timer timer = new Timer(1, null );
        Physics physics = new Physics(timer,this, gameManager);
        timer.addActionListener(physics);
        timer.start();

        
        InputListener inputListener = new InputListener(player,proxy,physics);

        



        addKeyListener(inputListener);
        addMouseMotionListener(inputListener);
        addMouseListener(inputListener);
        player.setFocusable(false);
        setFocusable(true);
        requestFocus();

        

        //add(text);
        add(player);

        add(points); 
        add(currentPoints);
        
        add(backGround);
        
        repaint();


    }

    


    
    public static void main(String[] args){

        proxy = new Main();
        proxy.sceneManager();


        //System.out.println(proxy.scores.maxScore[1]);
        
        
        

        

        
    }

}

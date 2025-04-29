package juegoTareaFinal;

import java.awt.Color;
import java.time.Duration;
import java.time.Instant;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;

import javax.swing.JLabel;

import juegoTareaFinal.src.fonts.CustomFonts;
import javax.swing.Timer;




public class GameManager implements Runnable{

    Player player;
    ArrayList<Bullet> bullets = new ArrayList<Bullet>();
    ArrayList<Enemy> enemies = new ArrayList<Enemy>();
    CustomFonts customFonts = new CustomFonts();
    Iterator <Enemy> enemiesIterator;
    Iterator<Bullet> bulletIterator;



    MainFrame mainFrame;
    InputListener inputListener;
    JLabel currentPoints = new JLabel();
    JLabel lifePoints = new JLabel();
    int points = 0;

    int bulletSize;
    int enemySize;

    boolean playing = true;
    

    boolean canMoveBullets= false;

    Instant beginTime = Instant.now();
    Long timer = 0l;
    Long animationTimer = 0l;

    double deltaTime;
    Instant deltaTime0;
    int sleep = 10;




    

    public GameManager(MainFrame mainFrame){

        this.mainFrame = mainFrame;
        player = new Player(mainFrame);

        bulletSize = mainFrame.getHeight()*1/100;
        enemySize = mainFrame.getHeight()*10/100;

        

    }




    @Override
    public void run() {

        inputListener = new InputListener(mainFrame);
        
        mainFrame.addMouseMotionListener(inputListener);
        mainFrame.addMouseListener(inputListener);
        mainFrame.addKeyListener(inputListener);
        setEnemyAtRandomPosition();
        
        currentPoints.setBounds(mainFrame.getWidth()/2 - mainFrame.getWidth()*7/100, 10, mainFrame.getWidth()*15/100, mainFrame.getHeight()*15/100);
        currentPoints.setText("Score: 000");
        currentPoints.setFont(customFonts.font);
        currentPoints.setForeground(Color.green);
        currentPoints.setBackground(Color.WHITE);


        lifePoints.setBounds(mainFrame.getWidth() - mainFrame.getWidth()*20/100 - 10  , 10, mainFrame.getWidth()*20/100, mainFrame.getHeight()*20/100);
        lifePoints.setText("life points: 3");
        lifePoints.setFont(customFonts.font);
        lifePoints.setForeground(Color.green);
        lifePoints.setBackground(Color.WHITE);


        mainFrame.add(lifePoints, 0);
        mainFrame.add(currentPoints, 0);
        mainFrame.add(player , 0);
        mainFrame.add(mainFrame.background);
        mainFrame.repaint();




        while(playing){

            

            //System.out.println("timer: " + timer);
    
            try{
                Thread.sleep(sleep);
            }catch(InterruptedException e){}

            deltaTime0 = Instant.now();
            timer = Duration.between(beginTime, Instant.now() ).getSeconds();
            //animationTimer = timer;

            moveAll();
            checkingColliders();
            

            if( true){
                animating();
                animationTimer = timer;
            }

            if(enemies.size() == 0){
                setEnemyAtRandomPosition();
                setEnemyAtRandomPosition();
                setEnemyAtRandomPosition();
            }

            if(player.lifePoints <= 0){
                mainFrame.score = points;
                mainFrame.gameOver();
                break;
            }

            removeLostEnemies();
            refreshPoints();



            mainFrame.repaint();
            mainFrame.requestFocus();
            System.gc();
            deltaTime = Duration.between(deltaTime0,Instant.now()).getNano() / 1e9;

            
            //System.out.println(deltaTime.getNano() / 1e9);
            //System.out.println(deltaTime);
            sleep = (int)( Math.abs((0.033 - deltaTime ))  *  1000);

            

  
        }
        
    
    }


    public void refreshPoints(){

        currentPoints.setText( "Score: " +  points );
        lifePoints.setText("life points: " + player.lifePoints);

    }



    public void addBullet(double vectorX, double vectorY){

        canMoveBullets = false;

        //System.out.println("balla creada");
        Bullet newBullet = new Bullet((int)player.getBounds().getCenterX(), (int)player.getBounds().getCenterY(), vectorX, vectorY, bulletSize, timer);
        //System.out.println( "vector x: " + newBullet.vectorX  + " vector y: " + newBullet.vectorY );
        mainFrame.add(newBullet,1);
        bullets.add(newBullet);
        canMoveBullets = true;

    }

    public void moveAll(){
        for(int i = 0; i < bullets.size() ; i++){
            bullets.get(i).moveTo();
            if( timer -   bullets.get(i).createdTime  >  5l){

                mainFrame.remove(bullets.remove(i));

                //mainFrame.remove(bullets.get(i));
                //bullets.remove(i);
                //System.out.println("objetos: " + mainFrame.getContentPane().getComponentCount());
            }
        }

        for(int i = 0; i < enemies.size() ; i++){
            enemies.get(i).moveTo();
        }

        player.moving(inputListener.x, inputListener.y);

    }

    public void animating(){
        player.nextFrame();
        enemiesIterator = enemies.iterator();
        while(enemiesIterator.hasNext()){
            Enemy nextenemy = enemiesIterator.next();
            nextenemy.nextFrame();
        }

        
    }

    public void setEnemyAtRandomPosition(){
        Random random = new Random();
        Enemy enemy = new Enemy(enemySize, Math.abs(random.nextInt(mainFrame.getWidth()) - enemySize )  , Math.abs( random.nextInt(mainFrame.getHeight()) - enemySize)  , timer);
        enemies.add(enemy);
        mainFrame.add(enemy,0);
    }

    public void checkingColliders(){


        enemiesIterator = enemies.iterator();
        while(enemiesIterator.hasNext()){
            Enemy nextEnemy = enemiesIterator.next();
            if(nextEnemy.boxCollider.isColliding(player.boxCollider)){
                //System.out.println("is collaiding");
                enemiesIterator.remove();
                mainFrame.remove(nextEnemy);
                player.lifePoints--;
                
                //System.out.println("vida del jugador: " + player.lifePoints);
                //mainFrame.repaint();
            }
            nextEnemy = null;
        }


        enemiesIterator = enemies.iterator();
        while(enemiesIterator.hasNext()){
            Enemy nextEnemy = enemiesIterator.next();
            bulletIterator = bullets.iterator();
            while(bulletIterator.hasNext()){
                Bullet nextBullet = bulletIterator.next();
                if(nextEnemy.boxCollider.isColliding(nextBullet.boxCollider)){
                    //System.out.println("is collaiding");
                    bulletIterator.remove();
                    mainFrame.remove(nextBullet);
                    nextEnemy.lifePoints--;
                    if(nextEnemy.lifePoints == 0){
                        enemiesIterator.remove();
                        mainFrame.remove(nextEnemy);
                        points++;
                    }
                }
            }
        }




    }

    

    public void removeLostEnemies(){

        for(int i = 0 ; i< enemies.size() ; i++){
            if( timer -   enemies.get(i).createdTime > 3l ){
                mainFrame.remove(enemies.remove(i));
            }
        }

    }

    public void stopPlaying(){
        mainFrame.score = points;
        mainFrame.gameOver();
        playing = false;
        
    }

    public void playing(){
        playing = true;
    }




    
}

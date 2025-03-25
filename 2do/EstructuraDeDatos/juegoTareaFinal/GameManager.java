package juegoTareaFinal;

import java.awt.Color;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;

import javax.swing.JLabel;

import juegoTareaFinal.src.fonts.CustomFonts;



public class GameManager implements Runnable{

    Player player;
    ArrayList<Bullet> bullets = new ArrayList<>();
    ArrayList<Enemy> enemies = new ArrayList<>();
    CustomFonts customFonts = new CustomFonts();
    Iterator <Enemy> enemiesIterator;
    Iterator<Bullet> bulletIterator;


    Physics physics;
    MainFrame mainFrame;
    InputListener inputListener;
    Scores scores;
    JLabel currentPoints = new JLabel();
    JLabel lifePoints = new JLabel();
    int points = 0;

    int bulletSize;
    int enemySize;
    Long timer = 0l;

    boolean canMoveBullets= false;

    




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


        lifePoints.setBounds(mainFrame.getWidth() - mainFrame.getWidth()*15/100 - 10  , 10, mainFrame.getWidth()*15/100, mainFrame.getHeight()*15/100);
        lifePoints.setText("life points: 3");
        lifePoints.setFont(customFonts.font);
        lifePoints.setForeground(Color.green);
        lifePoints.setBackground(Color.WHITE);




        


        mainFrame.add(lifePoints, 0);
        mainFrame.add(currentPoints, 0);
        mainFrame.add(player , 0);
        mainFrame.add(mainFrame.background);
        mainFrame.repaint();





        while(true){
            //System.out.println("el juego ha empezado");
    
            try{
                Thread.sleep(10);
            }catch(InterruptedException e){}
            timer++;

            moveBullets();
            checkingColliders();
            

            if(timer % 100l == 0)
                animating();

            if(enemies.size() == 0){
                setEnemyAtRandomPosition();
                setEnemyAtRandomPosition();
                setEnemyAtRandomPosition();
            }

            if(player.lifePoints == 0){
                mainFrame.gameOver();
                break;
            }

            removeLostEnemies();
            refreshPoints();
            mainFrame.repaint();
            mainFrame.requestFocus();
            System.gc();




  
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

    public void moveBullets(){
        for(int i = 0; i < bullets.size() ; i++){
            bullets.get(i).moveTo();
            if( timer -   bullets.get(i).createdTime  >  1000){

                mainFrame.remove(bullets.remove(i));

                //mainFrame.remove(bullets.get(i));
                //bullets.remove(i);
                //System.out.println("objetos: " + mainFrame.getContentPane().getComponentCount());
            }
        }

        for(int i = 0; i < enemies.size() ; i++){
            enemies.get(i).moveTo();
        }

    }

    public void animating(){
        player.nextFrame();
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
                
                System.out.println("vida del jugador: " + player.lifePoints);
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
            if( timer -   enemies.get(i).createdTime > 300l ){
                mainFrame.remove(enemies.remove(i));
            }
        }

    }




    
}

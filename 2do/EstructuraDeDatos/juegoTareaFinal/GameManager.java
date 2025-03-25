package juegoTareaFinal;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.concurrent.SynchronousQueue;
import java.util.Random;



public class GameManager implements Runnable{

    Player player;
    ArrayList<Bullet> bullets = new ArrayList<>();
    ArrayList<Enemy> enemies = new ArrayList<>();
    Iterator <Enemy> enemiesIterator;
    Iterator<Bullet> bulletIterator;


    Physics physics;
    MainFrame mainFrame;
    InputListener inputListener;

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

        mainFrame.add(player , 0);
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
            }
            
            mainFrame.repaint();
            mainFrame.requestFocus();
            System.gc();
  
        }
        
    
    }






    public void addBullet(double vectorX, double vectorY){

        canMoveBullets = false;

        //System.out.println("balla creada");
        Bullet newBullet = new Bullet((int)player.getBounds().getCenterX(), (int)player.getBounds().getCenterY(), vectorX, vectorY, bulletSize, timer);
        //System.out.println( "vector x: " + newBullet.vectorX  + " vector y: " + newBullet.vectorY );
        mainFrame.add(newBullet,1);
        bullets.addLast(newBullet);
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
    }

    public void animating(){
        player.nextFrame();
    }

    public void setEnemyAtRandomPosition(){
        Random random = new Random();
        Enemy enemy = new Enemy(enemySize, random.nextInt(mainFrame.getWidth()), random.nextInt(mainFrame.getHeight()));
        enemies.add(enemy);
        mainFrame.add(enemy);
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
                    }

                }

            }
        }


    }

    






    
}

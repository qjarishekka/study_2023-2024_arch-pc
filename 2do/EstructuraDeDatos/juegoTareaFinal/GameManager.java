package juegoTareaFinal;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.concurrent.SynchronousQueue;



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


        mainFrame.add(player);



        while(true){
            //System.out.println("el juego ha empezado");


    
            try{
                Thread.sleep(10);
            }catch(InterruptedException e){}
            timer++;



            moveBullets();
            if(timer % 100l == 0)
                animating();


            


  
        }
        
    
    }






    public void addBullet(double vectorX, double vectorY){

        canMoveBullets = false;

        //System.out.println("balla creada");
        Bullet newBullet = new Bullet((int)player.getBounds().getCenterX(), (int)player.getBounds().getCenterY(), vectorX, vectorY, bulletSize, timer);
        //System.out.println( "vector x: " + newBullet.vectorX  + " vector y: " + newBullet.vectorY );
        mainFrame.add(newBullet,0);
        bullets.addLast(newBullet);
        canMoveBullets = true;



    }




    public void moveBullets(){


        for(int i = 0; i < bullets.size() ; i++){
            bullets.get(i).moveTo();
            bullets.get(i).boxCollider.refresBoxCollider();

            if( timer -   bullets.get(i).createdTime  >  100){
                mainFrame.remove(bullets.get(i));
                bullets.remove(i);
                System.out.println("objetos: " + mainFrame.getContentPane().getComponentCount());
            }
        }




    }

    public void animating(){
        player.nextFrame();
    }




    
}

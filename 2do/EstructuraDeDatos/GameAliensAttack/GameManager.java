package GameAliensAttack;

import java.awt.Point;
import java.awt.event.KeyEvent;
import java.time.Duration;
import java.time.Instant;
import java.util.ArrayList;

import GameAliensAttack.Entities.Enemy;
import GameAliensAttack.Entities.Player;
import GameAliensAttack.GameEngine.*;
import GameAliensAttack.Scenes.*;
import GameAliensAttack.UI.*;

public class GameManager extends MonoBehavior {

    static public GameManager proxy;
    static public Scores scores = new Scores();

    public MenuPanel menuPanel = new MenuPanel();
    public GamePanel gamePanel = new GamePanel();
    public PausePanel pausePanel = new PausePanel();
    public OptionsPanel optionsPanel = new OptionsPanel();
    public GameOver gameOverPanel = new GameOver(this);
    
    static public boolean paused = false;
    static public boolean options = false;
    static public boolean gameLost = false;
    static public int difficulty = 1;
    static public int score = 0;
    public Player player = new Player();;
    int currentLevel = 0;

    double chronometer = 0;
    Instant time = Instant.now();


public GameManager() {
        SceneManager.setScene("Menu");
        GameEngine.pause();
        proxy = this;

        // Hilo separado que siempre escucha Escape
    new Thread(() -> {
        while (true) {
            if (Input.isKeyJustPressed(KeyEvent.VK_ESCAPE)) {
                if (!paused && !SceneManager.currentScene.equals("Menu")) {
                    UIManager.showUIPanel("Pause");
                    GameEngine.pause();
                    paused = true;
                } else {
                    UIManager.hideUIPanel("Pause");
                    if(SceneManager.currentScene.equals("Game"))
                        GameEngine.play();
                    MenuPanel.enable = true;
                    paused = false;
                }
            
                
                if(options){
                    UIManager.hideUIPanel("Options");
                        menuPanel.options.setEnabled(true);
                        menuPanel.playButton.setEnabled(true);
                }else{
                    if(SceneManager.currentScene.equals("Menu")){
                        UIManager.showUIPanel("Options");
                        MenuPanel.enable = false;
                        menuPanel.options.setEnabled(false);
                        menuPanel.playButton.setEnabled(false);
                        
                    }
                    
                }
                if(SceneManager.currentScene.equals("Menu")){
                    options = !options;
                }
                    
                    
                    try {
                        Thread.sleep(150); 
                    } catch (InterruptedException e) {}
            }
                
                

            }
        }).start();
    }





    @Override
    public void update() {
        

        if(!GameEngine.isThereObjectByTag("Enemy") && SceneManager.currentScene.equals("Game")){
            currentLevel++;
            setLevel(currentLevel);

        }
        showGameOver();
        GamePanel.setScore(score);
        GamePanel.setLife(player.life);        

    }

    public void setLevel(int numberOfLevel){


        ArrayList<Point> enemysPosition = getLocationOfNewEnemy(numberOfLevel); 
        
        for(int i = 1 ; i <= numberOfLevel ; i++){

            if(numberOfLevel == 1){
                
                
                SceneManager.addToSceneByTag(player, "Game");
            }
            player.setLocation((MainFrame.width - player.playerSize)/2, (MainFrame.height - player.playerSize)/2);
            Enemy enemy = new Enemy();
            enemy.setLifePoints(  (int)(Math.pow(difficulty, 2) ));
            enemy.setLocation(enemysPosition.get(i-1));
            enemy.setTargetedEntity(player);
            SceneManager.addToSceneByTag(enemy, "Game");

        }
    }

    public void showGameOver(){

        if(Player.proxy.life <= 0 && !gameLost){
            GameEngine.pause();
            UIManager.showUIPanel("GameOver");
            gameLost = true;
        }
      
    }


    public void playAgain(){

        SceneManager.removeFromSceneByTag("Enemy");
        SceneManager.setScene("Game");

        currentLevel = 0;
        player.life = 3;
        score = 0;
        gameLost = false;
        gameOverPanel.insertYourName.setFocusable(true);;
        gameOverPanel.feedback.setText("");
        setLevel(currentLevel);
        GameEngine.play();

    }

    public ArrayList<Point> getLocationOfNewEnemy(int enemyCounter) {
        int distanceConstant = 400;
        ArrayList<Point> arrayOfEnemyLocations = new ArrayList<>(enemyCounter);
        
        // Centro del círculo
        Point center = new Point((MainFrame.width - Enemy.size) / 2, (MainFrame.height - Enemy.size) / 2);

        double angleStep = 2 * Math.PI / enemyCounter;  // Ángulo entre enemigos

        double startingAngle;
        if (enemyCounter % 2 == 0) {
            // Si es par, primer punto justo arriba (PI/2)
            startingAngle = -Math.PI / 2;
        } else {
            // Si es impar, dos primeros puntos simétricos alrededor del tope
            startingAngle = Math.PI / 2 - angleStep / 2;
        }

        for (int i = 0; i < enemyCounter; i++) {
            double angle = startingAngle + i * angleStep;

            int x = (int) (center.x + Math.cos(angle) * distanceConstant);
            int y = (int) (center.y + Math.sin(angle) * distanceConstant);

            arrayOfEnemyLocations.add(new Point(x, y));
        }

        return arrayOfEnemyLocations;
    }


}


package GameAliensAttack;



public class SceneManager {

    GamePanel gamePanel;
    MenuPanel menuPanel;
    PausePanel pausePanel;


    public SceneManager(){

        gamePanel = new GamePanel();
        menuPanel = new MenuPanel(this);
        //pausePanel = new pausePanel();

    }



    public void setScene(String sceneName){

        if(sceneName.equals("Menu")){
            MainFrame.proxy.remove(gamePanel);
            MainFrame.proxy.add(menuPanel);
        }
        if(sceneName.equals("Game")){
            MainFrame.proxy.remove(menuPanel);
            MainFrame.proxy.add(gamePanel);
            MainFrame.proxy.repaint();
        }
        if(sceneName.equals("Pause")){
            
            //System.out.println("scene changed");
        }
        //System.out.println("Scene's name not found");
        

    }

    
}

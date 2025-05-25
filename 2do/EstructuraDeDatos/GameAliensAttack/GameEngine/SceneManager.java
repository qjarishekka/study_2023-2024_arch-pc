package GameAliensAttack.GameEngine;

import java.util.ArrayList;

import javax.swing.JPanel;

import GameAliensAttack.MainFrame;
import GameAliensAttack.Scenes.GamePanel;
import GameAliensAttack.Scenes.MenuPanel;
import GameAliensAttack.UI.PausePanel;

public class SceneManager {

    public static String currentScene = "";

    public SceneManager(){

        MainFrame.proxy.add(Scene.scenesCollection.get(0));
        currentScene = Scene.scenesCollection.get(0).getTag();
    }

    public static void setScene(String sceneName){

        for(Scene scene : Scene.scenesCollection){
            if(scene.getTag().matches(sceneName)){
                MainFrame.proxy.add(scene);
                currentScene = scene.getTag();
            }else{
                MainFrame.proxy.remove(scene);
            }
        }

        MainFrame.proxy.revalidate();
        MainFrame.proxy.repaint();

    }

    public static void addToSceneByTag(MonoBehavior object , String sceneName){
        for(Scene scene : Scene.scenesCollection){
            if(scene.getTag().equals(sceneName))
                scene.add(object,0);
        }
        //System.out.println(Scene.scenesCollection.get(0).tag);
        MainFrame.proxy.revalidate();
        MainFrame.proxy.repaint();

    }

    public static void removeFromSceneByTag(MonoBehavior object , String sceneName){
        for(Scene scene : Scene.scenesCollection){
            if(scene.getTag().equals(sceneName)){
                scene.remove(object);
                GameEngine.removeObject(object);
            }    
        }
        MainFrame.proxy.revalidate();
        MainFrame.proxy.repaint();
        //System.out.println(Scene.scenesCollection.get(0).tag);
    }

    public static Scene getSceneByTag(String nameScene){
        for(Scene scene : Scene.scenesCollection){
            if(scene.tag.equals(nameScene)){
                return scene;
            }
        }
        return null;
    }

    






    
}

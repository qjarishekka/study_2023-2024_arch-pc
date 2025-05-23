package GameAliensAttack.GameEngine;

import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.time.Duration;
import java.time.Instant;
import java.util.ArrayList;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;

public class Animator{

    public static ArrayList<Animator> animatorsCollection = new ArrayList<>(0);
    public static ArrayList<Animator> animatorsBuffer = new ArrayList<>();

    BufferedImage bufferedImage[];
    int size = 1;
    int frameID = 0;
    double framesPerSecond = 1;
    MonoBehavior object;
    double chronometer = 0;
    Instant time;
    private boolean play = false;
    
    
    public Animator(String path , MonoBehavior object, int size){

        this.object = object;
        this.size = size;

        File dir = new File(path);
        File[] files = dir.listFiles();
        bufferedImage = new BufferedImage[files.length];
        for(int i = 0; i < files.length ; i++){ //
            try{
                bufferedImage[i] = ImageIO.read(files[i]);
            }catch(IOException e){}
        }

        animatorsBuffer.add(this);
        time = Instant.now();
    
    }



    public void setFPS(double framesPerSecond){

        this.framesPerSecond = framesPerSecond;

    }

    public Image getIgame(int index){
        if(index< bufferedImage.length) return bufferedImage[index].getScaledInstance(size, size, 0);

        return bufferedImage[0];
    }

    public void play(){
        play = true;
    }

    public void stop(){
        play = false;
    }

    public void animate(){
        
        if(play){

            if(chronometer >= framesPerSecond ){
                frameID++;
                if(frameID >= bufferedImage.length){
                    frameID = 0;
                    object.setIcon(new ImageIcon(bufferedImage[0].getScaledInstance(size, size, 0)));
                }else{
                    object.setIcon(new ImageIcon(bufferedImage[frameID].getScaledInstance(size, size, 0)));
                }

                time = Instant.now();
            }
            chronometer = Duration.between(time, Instant.now()).getSeconds() + Duration.between(time, Instant.now()).getNano()/1e9;
        }
    }



    

}

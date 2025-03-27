

import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class Animator {

    BufferedImage bufferedImage[];
    int frameID= 0;
    
    public Animator(String path){

        File dir = new File(path);
        File[] files = dir.listFiles();
        bufferedImage = new BufferedImage[files.length];
        for(int i = 0; i < files.length ; i++){ //
            try{
                bufferedImage[i] = ImageIO.read(files[i]);
            }catch(IOException e){}
        }
        

        //System.out.println("se creo el animator");
    }

    public Image nextFrame(){


        if(frameID < bufferedImage.length-1){
            frameID++;
            return bufferedImage[frameID-1];
        }else{
            frameID = 0;
            return bufferedImage[frameID];
        }

    
    }

}

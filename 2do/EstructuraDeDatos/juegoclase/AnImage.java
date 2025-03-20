package juegoclase;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.awt.image.ImageObserver;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.io.File;
import java.io.IOException;

public class AnImage extends JLabel{

    BufferedImage [] images;
    int frameID;

    public AnImage(String path){ 
        //aqui damos la ruta a la carpeta de imagenes;
        File dir = new File(path);
        File[] files = dir.listFiles();
        images = new BufferedImage[files.length];
        for(int i = 0; i < files.length ; i++){ //
            try{
                images[i] = ImageIO.read(files[i]);
            }catch(IOException e){}
        }
    }

    @Override
    public void paint(Graphics g){
        g.drawImage(images[frameID], 0, 0,null);
    }
    
}

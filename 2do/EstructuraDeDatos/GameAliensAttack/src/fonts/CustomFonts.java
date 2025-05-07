package GameAliensAttack.src.fonts;

import java.awt.Font;
import java.io.File;
import java.io.InputStream;
import java.util.stream.Stream;

import javax.xml.transform.stream.StreamSource;

public class CustomFonts {
    public Font font(int size){
        Font temporalFont = new Font(null);
        try{
            InputStream inputStream = getClass().getResourceAsStream("Minecraft.ttf");
            temporalFont = Font.createFont(Font.TRUETYPE_FONT, inputStream);
        }catch(Exception e){
            System.err.println("Minecraft.ttf no se cargo correctamente");
            temporalFont = new Font("Papyrus",Font.PLAIN, 14);
        }
        Font tfont = temporalFont.deriveFont(0, size);
        return tfont;
    }
}

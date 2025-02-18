import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JComponent;

public class MyButtonlistener implements ActionListener{
    private JComponent component;
    private int dx, dy;
    int counter = 0;

    public MyButtonlistener(JComponent component, int dx, int dy){
        this.component = component;
        this.dx = dx;
        this.dy = dy;
    }

    @Override
    public void actionPerformed(ActionEvent e){
        component.setLocation(component.getX() + dx , component.getY() + dy);
        //button.setText("clicked " + counter);
        counter++;
    }

    //donde hay component habia Button, esto se hizo para poder mover las imagenes
    // en caso de querer mover un boton se puede usar volver a cambiar, pero la clase JComponent es mas general y nos permite usar esta funcion en mas casos


}

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class MyTextListener implements ActionListener{

    private JTextField input;
    private JLabel output;


    MyTextListener(JTextField ip, JLabel out){
        input = ip;
        output = out;
    }

    @Override
    public void actionPerformed(ActionEvent e){
        output.setText(input.getText());
        input.setText("");
        

    }

    //donde hay component habia Button, esto se hizo para poder mover las imagenes
    // en caso de querer mover un boton se puede usar volver a cambiar, pero la clase JComponent es mas general y nos permite usar esta funcion en mas casos


}

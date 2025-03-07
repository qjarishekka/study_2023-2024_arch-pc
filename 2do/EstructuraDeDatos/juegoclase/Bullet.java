package juegoclase;

import javax.swing.JLabel;

public class Bullet {
    double x, y , vx , vy;
    JLabel pic;
    public Bullet(JLabel pic){
        this.pic = pic;
        x = 0;
        y = 0;
        vx = 0;
        vy = 0;

    }

    void setLocation(double x, double y) {
        this.x = x;
        this.y = y;
        pic.setLocation((int)x, (int)y);
    }

    void shoot(double vx, double vy){
        this.vx = vx;
        this.vy = vy;
    }

    void move(double dt){
        x += vx * dt;
        y += vy * dt;
        vy += Physics.GRAVITY * dt;
        pic.setLocation((int)x, (int)y);
    }

}

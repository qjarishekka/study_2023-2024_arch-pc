package GameAliensAttack.GameEngine;

import java.awt.Point;
import java.awt.event.*;
import java.util.HashSet;
import java.util.Set;

public class Input implements KeyListener, MouseListener, MouseMotionListener {

    private static final Set<Integer> pressedKeys = new HashSet<>();
    private static final Set<Integer> justPressedKeys = new HashSet<>();
    private static boolean mousePressed = false;
    private static boolean mouseClicked = false;
    private static Point cursor = new Point(0, 0);

    public static boolean isKeyPressed(int keyCode) {
        return pressedKeys.contains(keyCode);
    }

    public static boolean isKeyJustPressed(int keyCode) {
        return justPressedKeys.contains(keyCode);
    }

    public static void endFrame() {
        justPressedKeys.clear();
        mouseClicked = false;
    }

    public static boolean isMousePressed() {
        return mousePressed;
    }

    public static boolean triggerMouseClick() {
        if (mouseClicked) {
            return true;
        }
        return false;
    }

    public static Point getCursorPosition() {
        return new Point(cursor);
    }

    public static double getHorizontalAxis() {
        int axis = 0;
        if (isKeyPressed(KeyEvent.VK_A)) axis -= 1;
        if (isKeyPressed(KeyEvent.VK_D)) axis += 1;
        return axis;
    }

    public static double getVerticalAxis() {
        int axis = 0;
        if (isKeyPressed(KeyEvent.VK_W)) axis -= 1;
        if (isKeyPressed(KeyEvent.VK_S)) axis += 1;
        return axis;
    }


    @Override
    public void keyPressed(KeyEvent e) {
        int code = e.getKeyCode();
        if (!pressedKeys.contains(code)) {
            justPressedKeys.add(code);
        }
        pressedKeys.add(code);
    }

    @Override
    public void keyReleased(KeyEvent e) {
        pressedKeys.remove(e.getKeyCode());
    }

    @Override
    public void keyTyped(KeyEvent e) {}


    @Override
    public void mousePressed(MouseEvent e) {
        mousePressed = true;
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        mousePressed = false;
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        mouseClicked = true;
    }

    @Override
    public void mouseEntered(MouseEvent e) {}

    @Override
    public void mouseExited(MouseEvent e) {}

  
    @Override
    public void mouseMoved(MouseEvent e) {
        cursor = e.getPoint();
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        mouseClicked = true;
        cursor = e.getPoint();
    }
}

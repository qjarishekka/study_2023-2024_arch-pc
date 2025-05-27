package GameAliensAttack.GameEngine;

import java.awt.*;
import java.awt.event.*;
import java.util.HashSet;
import java.util.Set;

public class Input {

    private static final Set<Integer> pressedKeys = new HashSet<>();
    private static final Set<Integer> justPressedKeys = new HashSet<>();
    private static boolean mousePressed = false;
    private static boolean mouseClicked = false;
    private static Point cursor = new Point(0, 0);

    // ======= INICIALIZACIÓN GLOBAL =======
    public static void initialize(Component rootComponent) {
        // Teclado global
        KeyboardFocusManager.getCurrentKeyboardFocusManager().addKeyEventDispatcher(e -> {
            synchronized (Input.class) {
                int keyCode = e.getKeyCode();
                switch (e.getID()) {
                    case KeyEvent.KEY_PRESSED:
                        if (!pressedKeys.contains(keyCode)) {
                            justPressedKeys.add(keyCode);
                        }
                        pressedKeys.add(keyCode);
                        break;
                    case KeyEvent.KEY_RELEASED:
                        pressedKeys.remove(keyCode);
                        break;
                }
                return false; // Dejar pasar el evento (para JTextField, etc.)
            }
        });

        // Mouse (listener en el componente raíz)
        rootComponent.addMouseListener(new MouseAdapter() {
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
        });

        rootComponent.addMouseMotionListener(new MouseMotionAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                cursor = e.getPoint();
            }

            @Override
            public void mouseDragged(MouseEvent e) {
                mousePressed = true;
                cursor = e.getPoint();
            }
        });

        rootComponent.setFocusable(true);
        rootComponent.requestFocusInWindow();
    }

    // ======= INPUT API =========
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
        return mouseClicked;
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
}

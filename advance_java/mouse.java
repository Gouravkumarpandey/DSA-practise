import java.awt.*;
import java.awt.event.*;

public class Mouse extends Frame implements MouseListener {
    Button bred;

    Mouse() {
        bred = new Button("Red");
        bred.setBounds(150, 150, 30, 10);
        bred.addMouseListener(this);
        add(bred);
        setLayout(null);
        setVisible(true);
        setSize(300, 300);
    }

    public void mouseClicked(MouseEvent e) {
        bred.setBackground(Color.red);
    }

    public void mouseEntered(MouseEvent e) {}
    public void mouseExited(MouseEvent e) {}
    public void mousePressed(MouseEvent e) {}
    public void mouseReleased(MouseEvent e) {}

    public static void main(String args[]) {
        Mouse frame = new Mouse();
    }
}

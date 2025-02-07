import java.awt.*;
import java.awt.event.*;

public class Mouse3 extends Frame {
    Button bred;

    Mouse3() {
        bred = new Button("Red");
        bred.setBounds(150, 150, 30, 10);
        bred.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                bred.setBackground(Color.red);
            }

            public void mouseEntered(MouseEvent e) {
                bred.setBackground(Color.blue);
            }
        });
        add(bred);
        setLayout(null);
        setVisible(true);
        setSize(300, 300);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                dispose();
            }
        });
    }

    public static void main(String args[]) {
        Mouse3 frame = new Mouse3();
    }
}
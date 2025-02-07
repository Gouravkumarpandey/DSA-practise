import java.awt.*;
import java.awt.event.*;

public class Mouse4 extends Frame {
    Button bred;

    Mouse4() {
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
        Mouse4 frame = new Mouse4();
    }
}

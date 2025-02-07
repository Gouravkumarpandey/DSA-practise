import java.awt.*;
import java.awt.event.*;

public class Mouse2 {
    public static void main(String[] args) {
        
        Frame frame = new Frame("Color");

        Button red = new Button("Red");
        Button blue = new Button("Blue");
        Button yellow = new Button("Yellow");

        red.setBounds(50, 50, 80, 30);
        blue.setBounds(150, 50, 80, 30);
        yellow.setBounds(250, 50, 80, 30);

        frame.add(red);
        frame.add(blue);
        frame.add(yellow);

        red.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                frame.setBackground(Color.RED);
            }
        });

        blue.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                frame.setBackground(Color.BLUE);
            }
        });

        yellow.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                frame.setBackground(Color.YELLOW);
            }
        });

        frame.setSize(400, 200);
        frame.setLayout(null);
        frame.setVisible(true);

        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }
}
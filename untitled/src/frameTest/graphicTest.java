package frameTest;

import javax.swing.*;
import java.awt.*;

public class graphicTest {
    public static void main(String[] args) {

        // Jlabel = a GUI display area for a string of text, an image, or both
        // ImageIcon image = new ImageIcon(".png");

        JLabel label = new JLabel();
        label.setText("This is a test");
        label.setHorizontalTextPosition(JLabel.CENTER);
        // label.setIcon(image);

        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500,500);
        frame.setVisible(true);
        frame.add(label);

        // myFrame myFrame = new myFrame();

    }
}

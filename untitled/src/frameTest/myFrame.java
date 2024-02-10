package frameTest;

import javax.swing.*;
import java.awt.*;

public class myFrame extends JFrame{
    public myFrame() {

        // JFrame = a GUI window to add components to

        this.setTitle("JFrame title goes here"); // sets title of frame
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // exit out of application
        this.setResizable(false); // prevent frame from being resized
        this.setSize(420, 420); // sets the x-dimension and y-dimension of frame
        this.setVisible(true); // make frame visible

        ImageIcon image = new ImageIcon("test"); // create an ImageIcon (using .png format)
        this.setIconImage(image.getImage()); // change icon of frame
        this.getContentPane().setBackground(new Color(0XFFFFFF)); // Change color of background
    }
}

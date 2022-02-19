import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ItemEvent;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

public class JRadioButtons extends JFrame {
    
    JLabel lblMessage = new JLabel("Choose your color");

    ButtonGroup buttonGroup = new ButtonGroup();
    JRadioButton rdoRed = new JRadioButton("Red");
    JRadioButton rdoGreen = new JRadioButton("Green");
    JRadioButton rdoBlue = new JRadioButton("Blue");
    
    JPanel pnlPreview = new JPanel();
    JButton btnQuit = new JButton("Quit");

    public JRadioButtons() {
        super( "Exemple d'utilisation de la classe JRadioButton" );
        
        JPanel contentPane = (JPanel) getContentPane();
        contentPane.add( lblMessage, BorderLayout.NORTH );
        
        JPanel pnlLeft = new JPanel( new GridLayout( 3, 1 ) );
        // On cherche à imposer la largeur
        pnlLeft.setPreferredSize( new Dimension( 100, 0 ) );
        
        rdoRed.setSelected( true );
        pnlLeft.add( rdoRed );
        buttonGroup.add( rdoRed );
        rdoRed.addItemListener( this::radioButtons_itemStateChanged );
        
        pnlLeft.add( rdoGreen );
        buttonGroup.add( rdoGreen );
        rdoGreen.addItemListener( this::radioButtons_itemStateChanged );
        
        pnlLeft.add( rdoBlue );
        this.buttonGroup.add( rdoBlue );
        rdoBlue.addItemListener( this::radioButtons_itemStateChanged );

        contentPane.add( pnlLeft, BorderLayout.WEST );
        
        pnlPreview.setBackground(Color.red);
        contentPane.add( pnlPreview, BorderLayout.CENTER );
        
        btnQuit.addActionListener( (e) -> dispose() );
        contentPane.add( btnQuit, BorderLayout.SOUTH );

        this.setSize(300,160);
        this.setLocationRelativeTo( null );
    }

    void radioButtons_itemStateChanged(ItemEvent e) {
        Object source = e.getSource();
        if (source == rdoRed) pnlPreview.setBackground(Color.red);
        if (source == rdoGreen) pnlPreview.setBackground(Color.green);
        if (source == rdoBlue) pnlPreview.setBackground(Color.blue);
    }

    public static void main(String[] args) throws Exception {
        JRadioButtons frame = new JRadioButtons();
        frame.setVisible( true );
    }

}

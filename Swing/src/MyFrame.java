import javax.swing.*;

import java.awt.LayoutManager;
import java.awt.event.*;
import java.awt.*;

public class MyFrame extends JFrame{
	JButton button1 = null;
	JButton button2 = null;
	JButton button3 = null;
	JPanel pane  = null;

	JTextArea txta = null;
	JScrollPane scrollpane = null;

	JMenuBar menubar = null;
	JMenu menu = null;
	JToolBar toolbar = null;



	private static final long serialVersionUID = 1L;
	String phrase1 = "bonjour111, Je suis Antonin de télécom paris!!!!";
	String phrase2 = "bonjour222, je suis Yining YANG de SJTU!!!";
	

	public static void main(String argv[ ]) {
		MyFrame toplevel = new MyFrame(); // en gris : optionnel
	}
	public MyFrame() {
		button1 = new JButton ("Ajout1");
		button2 = new JButton ("Ajout2");
		button3 = new JButton ("supprime");
		pane = new JPanel();

		txta = new JTextArea();
		scrollpane = new JScrollPane(txta);

		menubar = new JMenuBar();
		menu = new JMenu("Menu");
		toolbar = new JToolBar();
		menubar.add(menu);
		toolbar.add(menubar);
		

		getContentPane().setLayout(new BorderLayout()); // cette ligne est par defaut
		getContentPane().add(pane,BorderLayout.SOUTH);
		getContentPane().add(scrollpane,BorderLayout.CENTER);
		getContentPane().add(toolbar,BorderLayout.NORTH);
		pane.add(button1); // en gris : avant version 5
		pane.add(button2);
		pane.add(button3);




		button1.addActionListener(new button1Listener());
		button2.addActionListener(new button2Listener());
		button3.addActionListener(new button3Listener());


		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("MyFrame");
		pack(); // calcule la disposition spatiale
		setVisible(true); // rend l’interface visible
	} 


	class button1Listener implements ActionListener{
		@Override
		public void actionPerformed(ActionEvent e){
			txta.setText(phrase1);
			} 
	}
	class button2Listener implements ActionListener{
		@Override
		public void actionPerformed(ActionEvent e){
			txta.setText(phrase2);
			} 
	}
	class button3Listener implements ActionListener{
		@Override
		public void actionPerformed(ActionEvent e){
			System.exit(0);
			} 
	}

}

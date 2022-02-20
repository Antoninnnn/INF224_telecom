package clientapp;


import javax.swing.*;
import clientapp.Client;
import java.awt.LayoutManager;
import java.awt.event.*;
import java.awt.*;
import java.io.*;


/**
 * @class <MyFrame>
 * @brief The GUI for the client operation and request.
 */
public class MyFrame extends JFrame{
    String s_cmd = "";
    JLabel opMessage = null;

    ButtonGroup buttonGroup = null;
    JRadioButton rdo1 = null;
    JRadioButton rdo2 = null;
    JRadioButton rdo3 = null;
    JRadioButton rdo4 = null;
    JRadioButton rdo5 = null;
    
	JButton button1 = null;
	JButton button2 = null;
	JButton button3 = null;
	JPanel pane  = null;
    JPanel panecmd = null;
	JTextArea txta = null;
	JScrollPane scrollpane = null;

	JMenuBar menubar = null;
	JMenu menu = null;
	JToolBar toolbar = null;


	private static final long serialVersionUID = 1L;
    private static final String DEFAULT_HOST ="localhost";
    private static final int DEFAULT_PORT = 3331;
	String phrase1 = "bonjour111, Je suis Antonin de télécom paris!!!!";
	String phrase2 = "bonjour222, je suis Yining YANG de SJTU!!!";
	

	public static void main(String argv[ ]) {


        Client client = null;
        String response = "";
        
        String host = DEFAULT_HOST;
        int port = DEFAULT_PORT;
        try {
          client = new Client(host, port);
        }
        catch (Exception e) {
          System.err.println("Client: Couldn't connect to "+host+":"+port);
          System.exit(1);
        }
            
        System.out.println("Client connected to "+host+":"+port);
        MyFrame toplevel = new MyFrame(client); // en gris : optionnel
		toplevel.setVisible(true);
		toplevel.setTitle("My Frame");

    // pour lire depuis la console
    /*
        BufferedReader cin = new BufferedReader(new InputStreamReader(toplevel.txta.getText()));
    
        while (true) {
        System.out.print("Request: ");
        try {
            String request = cin.readLine();
            String response = client.send(request);
            System.out.println("Response: " + response);
            }
        catch (java.io.IOException e) {
            System.err.println("Client: IO error");
            return;
            }
        }*/

	}
	public MyFrame(Client client) {
        opMessage = new JLabel("Choose your operation");

        buttonGroup = new ButtonGroup();
        rdo1 = new JRadioButton("RechercherMultimedia");
        rdo2 = new JRadioButton("RechercherGroup");
        rdo3 = new JRadioButton("AfficherMultimedia");
        rdo4 = new JRadioButton("AfficherGroup");
        rdo5 = new JRadioButton("JouerMultimedia");



		button1 = new JButton ("Ajout1");
		button2 = new JButton ("Ajout2");
		button3 = new JButton ("supprime");
		pane = new JPanel();
        panecmd =new JPanel();
        panecmd.setLayout(new BorderLayout());
        panecmd.add( opMessage, BorderLayout.NORTH );


        //Cette partie manipule le buttons group of 5 operations
        JPanel pnlLeft = new JPanel( new GridLayout( 5, 1 ) );
        // On cherche à imposer la largeur
        pnlLeft.setPreferredSize( new Dimension( 200, 0 ) );
        //rdo1.setSelected( true );
        pnlLeft.add( rdo1 );
        buttonGroup.add( rdo1 );
        rdo1.addItemListener( this::radioButtons_itemStateChanged );
        
        pnlLeft.add( rdo2 );
        buttonGroup.add( rdo2 );
        rdo2.addItemListener( this::radioButtons_itemStateChanged );
        
        pnlLeft.add( rdo3 );
        this.buttonGroup.add( rdo3 );
        rdo3.addItemListener( this::radioButtons_itemStateChanged );
        pnlLeft.add( rdo4 );
        this.buttonGroup.add( rdo4 );
        rdo4.addItemListener( this::radioButtons_itemStateChanged );
        pnlLeft.add( rdo5 );
        this.buttonGroup.add( rdo5 );
        rdo5.addItemListener( this::radioButtons_itemStateChanged );


        panecmd.add( pnlLeft, BorderLayout.WEST );

        JPanel pnlnom = new JPanel();
        pnlnom.setLayout(new BorderLayout());
        pnlnom.add(new Label("Nom"),BorderLayout.NORTH);
        JTextField txtfield = new JTextField(20);
         	// 20 = nombre de colonnes
        txtfield.setPreferredSize(new Dimension(100,0));
        pnlnom.add(txtfield,BorderLayout.CENTER);
        JButton ok = new JButton("Ok");
        ok.addActionListener(e ->{
            s_cmd = s_cmd+" "+txtfield.getText()+"\n";
            System.out.println("Command sent is: "+s_cmd);
            txta.append(s_cmd);
            String response = client.send(s_cmd);
            System.out.println("Message returned: "+response);
            s_cmd="";
            //request = s_cmd
        });
        pnlnom.add(ok,BorderLayout.SOUTH);
        
        panecmd.add(pnlnom, BorderLayout.CENTER );
        

		txta = new JTextArea();
		scrollpane = new JScrollPane(txta);
        scrollpane.setPreferredSize(new Dimension(500,150));
        /*
        //test for menubar, menu and toolbar
		menubar = new JMenuBar();
		menu = new JMenu("Menu");
		toolbar = new JToolBar();
		menubar.add(menu);
		menu.add(new JButton("Button2"));
		menubar.add(toolbar);
		//toolbar.add(new JButton("Button1"));
		*/
		setJMenuBar(createMenuBar());
		getContentPane().setLayout(new BorderLayout()); // cette ligne est par defaut
		getContentPane().add(pane,BorderLayout.SOUTH);
        getContentPane().add(scrollpane,BorderLayout.EAST);
		getContentPane().add(panecmd,BorderLayout.WEST);
		getContentPane().add(createToolBar(),BorderLayout.NORTH);
		
		pane.add(button1); // en gris : avant version 5
		pane.add(button2);
		pane.add(button3);

		JPopupMenu popupMenu = this.createPopupMenu();      
        txta.addMouseListener( new MouseAdapter() {
            @Override public void mousePressed( MouseEvent event ) {
                if ( event.isPopupTrigger() ) {
                    popupMenu.show( event.getComponent(), event.getX(), event.getY() );
                }
            }
        } );  




		button1.addActionListener(new button1Listener());
		button2.addActionListener(new button2Listener());
		button3.addActionListener(new button3Listener());


		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("MyFrame");
		pack(); // calcule la disposition spatiale
		setVisible(true); // rend l’interface visible
	} 
    
    void radioButtons_itemStateChanged(ItemEvent e) {
        //s_cmd= (e.getSource()).getText();
        
        //txta.setText(e.toString());
        //return e.toString();
        Object source = e.getSource();
        //s_cmd =source.toString();
        if (source == rdo1) s_cmd = rdo1.getText();
        if (source == rdo2) s_cmd = rdo2.getText();
        if (source == rdo3) s_cmd = rdo3.getText();
        if (source == rdo4) s_cmd = rdo4.getText();
        if (source == rdo5) s_cmd = rdo5.getText();


        System.out.println("operation chosen is "+s_cmd);
        
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

	    
    /* Methode de construction de la barre de menu */
    private JMenuBar createMenuBar() {

        // La barre de menu à proprement parler
        JMenuBar menuBar = new JMenuBar();

        // Définition du menu déroulant "File" et de son contenu
        JMenu mnuFile = new JMenu( "File" );
        mnuFile.setMnemonic( 'F' );

        /*JMenuItem mnuNewFile =*/ mnuFile.add( actNew );
        mnuFile.addSeparator();
        mnuFile.add( actOpen );
        mnuFile.add( actSave );
        mnuFile.add( actSaveAs );
        mnuFile.addSeparator();
        mnuFile.add( actExit );
        
        menuBar.add(mnuFile);
        
        // Définition du menu déroulant "Edit" et de son contenu
        JMenu mnuEdit = new JMenu( "Edit" );
        mnuEdit.setMnemonic( 'E' );
        
        mnuEdit.add( actUndo );
        mnuEdit.add( actRedo );
        mnuEdit.addSeparator();
        mnuEdit.add( actCopy );
        mnuEdit.add( actCut );
        mnuEdit.add( actPaste );

        menuBar.add(mnuEdit);

        // Définition du menu déroulant "Help" et de son contenu
        JMenu mnuHelp = new JMenu( "Help" );
        mnuHelp.setMnemonic( 'H' );
        
        menuBar.add( mnuHelp );
        
        return menuBar;
    }

    /* Methode de construction de la barre d'outils */
    private JToolBar createToolBar() {
        JToolBar toolBar = new JToolBar();

        toolBar.add( actNew ).setHideActionText( true );
        toolBar.addSeparator();
        toolBar.add( actOpen ).setHideActionText( true );
        toolBar.add( actSave ).setHideActionText( true );
        toolBar.add( actSaveAs ).setHideActionText( true );
        toolBar.addSeparator();
        toolBar.add( actExit ).setHideActionText( true );
           
        return toolBar;
    }

    /* Methode de construction du menu contextuel */
    private JPopupMenu createPopupMenu() {
        JPopupMenu popupMenu = new JPopupMenu();
        
        popupMenu.add( actUndo );
        popupMenu.add( actRedo );
        popupMenu.addSeparator();
        popupMenu.add( actCopy );
        popupMenu.add( actCut );
        popupMenu.add( actPaste );

        return popupMenu;
    }

    /* Nos diverses actions */
    private AbstractAction actNew = new AbstractAction() {  
        {
            putValue( Action.NAME, "New File..." );
            putValue( Action.SMALL_ICON, new ImageIcon( "icons/new.png" ) );
            putValue( Action.MNEMONIC_KEY, KeyEvent.VK_N );
            putValue( Action.SHORT_DESCRIPTION, "New file (CTRL+N)" );
            putValue( Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_N, KeyEvent.CTRL_DOWN_MASK ) ); 
        }
        
        @Override public void actionPerformed( ActionEvent e ) {
            System.out.println( "New" );
        }
    };

    private AbstractAction actOpen = new AbstractAction() {  
        {
            putValue( Action.NAME, "Open File..." );
            putValue( Action.SMALL_ICON, new ImageIcon( "icons/open.png" ) );
            putValue( Action.MNEMONIC_KEY, KeyEvent.VK_O );
            putValue( Action.SHORT_DESCRIPTION, "Open file (CTRL+O)" );
            putValue( Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_O, KeyEvent.CTRL_DOWN_MASK ) ); 
        }
        
        @Override public void actionPerformed( ActionEvent e ) {
            System.out.println( "Open" );
        }
    };

    private AbstractAction actSave = new AbstractAction() {  
        {
            putValue( Action.NAME, "Save File" );
            putValue( Action.SMALL_ICON, new ImageIcon( "icons/save.png" ) );
            putValue( Action.MNEMONIC_KEY, KeyEvent.VK_S );
            putValue( Action.SHORT_DESCRIPTION, "Save file (CTRL+S)" );
            putValue( Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_S, KeyEvent.CTRL_DOWN_MASK ) ); 
        }
        
        @Override public void actionPerformed( ActionEvent e ) {
            System.out.println( "Save" );
        }
    };
   
    private AbstractAction actSaveAs = new AbstractAction() {  
        {
            putValue( Action.NAME, "Save As..." );
            putValue( Action.SMALL_ICON, new ImageIcon( "icons/save_as.png" ) );
            putValue( Action.MNEMONIC_KEY, KeyEvent.VK_A );
            putValue( Action.SHORT_DESCRIPTION, "Save file" );
        }
        
        @Override public void actionPerformed( ActionEvent e ) {
            System.out.println( "Save as" );
        }
    };
   
    private AbstractAction actExit = new AbstractAction() {  
        {
            putValue( Action.NAME, "Exit" );
            putValue( Action.SMALL_ICON, new ImageIcon( "icons/exit.png" ) );
            putValue( Action.MNEMONIC_KEY, KeyEvent.VK_X );
            putValue( Action.SHORT_DESCRIPTION, "Exit (ALT+F4)" );
            putValue( Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_F4, KeyEvent.ALT_DOWN_MASK ) ); 
        }
        
        @Override public void actionPerformed( ActionEvent e ) {
            System.out.println( "Exit" );
			System.exit(0);
        }
    };

    private AbstractAction actUndo = new AbstractAction() {  
        {
            putValue( Action.NAME, "Undo" );
            putValue( Action.SMALL_ICON, new ImageIcon( "icons/undo.png" ) );
            putValue( Action.MNEMONIC_KEY, KeyEvent.VK_U );
            putValue( Action.SHORT_DESCRIPTION, "Undo (CTRL+Z)" );
            putValue( Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_Z, KeyEvent.CTRL_DOWN_MASK ) ); 
        }
        
        @Override public void actionPerformed( ActionEvent e ) {
            System.out.println( "Undo" );
        }
    };

    private AbstractAction actRedo = new AbstractAction() {  
        {
            putValue( Action.NAME, "Redo" );
            putValue( Action.SMALL_ICON, new ImageIcon( "icons/redo.png" ) );
            putValue( Action.MNEMONIC_KEY, KeyEvent.VK_R );
            putValue( Action.SHORT_DESCRIPTION, "Redo (CTRL+U)" );
            putValue( Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_U, KeyEvent.CTRL_DOWN_MASK ) ); 
        }
        
        @Override public void actionPerformed( ActionEvent e ) {
            System.out.println( "Redo" );
        }
    };

    private AbstractAction actCopy = new AbstractAction() {  
        {
            putValue( Action.NAME, "Copy" );
            putValue( Action.SMALL_ICON, new ImageIcon( "icons/copy.png" ) );
            putValue( Action.MNEMONIC_KEY, KeyEvent.VK_C );
            putValue( Action.SHORT_DESCRIPTION, "Copy (CTRL+C)" );
            putValue( Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_C, KeyEvent.CTRL_DOWN_MASK ) ); 
        }
        
        @Override public void actionPerformed( ActionEvent e ) {
            System.out.println( "Copy" );
        }
    };

    private AbstractAction actCut = new AbstractAction() {  
        {
            putValue( Action.NAME, "Cut" );
            putValue( Action.SMALL_ICON, new ImageIcon( "icons/cut.png" ) );
            putValue( Action.MNEMONIC_KEY, KeyEvent.VK_T );
            putValue( Action.SHORT_DESCRIPTION, "Cut (CTRL+X)" );
            putValue( Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_X, KeyEvent.CTRL_DOWN_MASK ) ); 
        }
        
        @Override public void actionPerformed( ActionEvent e ) {
            System.out.println( "Cut" );
        }
    };

    private AbstractAction actPaste = new AbstractAction() {  
        {
            putValue( Action.NAME, "Paste" );
            putValue( Action.SMALL_ICON, new ImageIcon( "icons/paste.png" ) );
            putValue( Action.MNEMONIC_KEY, KeyEvent.VK_P );
            putValue( Action.SHORT_DESCRIPTION, "Paste (CTRL+V)" );
            putValue( Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_V, KeyEvent.CTRL_DOWN_MASK ) ); 
        }
        
        @Override public void actionPerformed( ActionEvent e ) {
            System.out.println( "Paste" );
        }
    };
	

}

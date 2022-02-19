import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class LesComponents extends JFrame 
                           implements ActionListener {

  JTextField textField;
  JTextArea textArea;
  JCheckBox[] checkboxes = new JCheckBox[3];


  public static void main(String argv[]) {
    LesComponents toplevel = new LesComponents();
    // initialiser le titre, la disposition et rendre visible
    toplevel.setTitle("Les Components");
    toplevel.pack();
    toplevel.show();
  }

  public LesComponents() {
    Container contentPane = getContentPane();

    // BorderLayout = disposition de type "points cardinaux"
    // ==> emploi spécifique de la methode add() esnuite
    contentPane.setLayout(new BorderLayout());

    // creer un JPanel (Conteneur interne) et les widgets inclus
    // panel1 sera place au "nord" de la fenetre principale
    JPanel panel1 = new JPanel();
    contentPane.add(BorderLayout.NORTH, panel1);

    panel1.add(new JLabel("Valeur"));

    //NB: textField est une variable d'instance
    textField = new JTextField(20); 	// 20 = nombre de colonnes
    textField.addActionListener(this);
    panel1.add(textField);

    //NB: ok est une variable locale (i.e. locale a la methode)
    JButton ok = new JButton("Ok");
    ok.addActionListener(this);
    panel1.add(ok);


    // Deuxieme JPanel (place au "sud" de la fenetre principale)
    JPanel panel2 = new JPanel(); 
    contentPane.add(BorderLayout.SOUTH, panel2);

    checkboxes[0] = new JCheckBox("Oui", true);
    checkboxes[1] = new JCheckBox("Non",false);
    checkboxes[2] = new JCheckBox("Bof");
    panel2.add(checkboxes[0]);
    panel2.add(checkboxes[1]);
    panel2.add(checkboxes[2]);

    checkboxes[0].addActionListener(e -> System.out.println(" - command: " + e.getActionCommand()+" selected "+checkboxes[0].isSelected())

    );


    // Zone de texte (placee au "centre" de la fenêtre principale)
    textArea = new JTextArea(10, 25);    // 10 lignes, 25 colonnes
    textArea.setEditable(false);	 // texte non modifiable

    contentPane.add(BorderLayout.CENTER, textArea);
  }


  // méthode appelée quand on clique sur le button Ok
  // ou quand on tape ENTER sur le TextField
  //
  public void actionPerformed(ActionEvent e) {
    String text = textField.getText();
    textArea.append(text + "\n");

    System.out.println(" - id: " + e.getID());
    System.out.println(" - command: " + e.getActionCommand());
  }
}

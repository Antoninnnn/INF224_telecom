import javax.swing.*;
import java.awt.*;
import java.awt.event.*;



// sous-classe de JFrame (fenetre principale d'une appli graphique)
public class LesBoutons extends JFrame 
                        implements ActionListener {

  JLabel label;
  JButton b1, b2, b3;

  public static void main(String argv[]) {
    // instancier la classe
    LesBoutons toplevel = new LesBoutons();

    // initialiser le titre, la disposition spatiale et rendre visible
    toplevel.setTitle("Les Boutons");
    toplevel.pack();
    //toplevel.show();
  }


  public LesBoutons() {
    // RAPPEL: il faut ajouter les enfants au contentPane et non 
    // directement au JFrame
    Container contentPane = getContentPane();

    // changer le layout (disposition spatiale) du JFrame
    // ==> associer le LayoutManager desire au contentPane
    contentPane.setLayout(new FlowLayout());

    // creer les autres widgets
    b1 = new JButton("Bouton 1");
    b2 = new JButton("Bouton 2");
    b3 = new JButton("Bouton 3");
    label = new JLabel("Message ...");
    label.setOpaque(true);

    // ajouter ces widgets au Frame
    contentPane.add(b1);
    contentPane.add(b2);
    contentPane.add(b3);
    contentPane.add(label);

    // attacher un ActionListener pour recuperer les clics souris
    b1.addActionListener(this);
    b2.addActionListener(this);
    b3.addActionListener(this);
  }


  public void actionPerformed(ActionEvent e) {
    int id = e.getID();
    Object which_button = e.getSource();
    String command = e.getActionCommand();
    String str = e.toString();

    // NB: cette meme méthode sera appelée lorsque l'on cliquera
    // sur l'un des TROIS boutons ==> il faudra distinguer ces appels 
    // via:  e.getSource()  ou  e.getActionCommand()

    System.out.println(" - str: " + str);
    System.out.println(" - id: " + id);
    System.out.println(" - command: " + command);
    System.out.println(" - source: " + which_button);
  }
}

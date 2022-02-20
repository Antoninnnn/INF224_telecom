package clientapp;
/*
import clientapp.*;
import java.io.*;
import java.net.*;
*/

/**
 * The file is not useful, just for test
 */
public class App {
    public static final String DEFAULT_HOST = "localhost";
    public static final int DEFAULT_PORT = 3331;

    
    
/*    public static void main(String[] args) throws Exception {
        MyFrame toplevel = new MyFrame(); // en gris : optionnel
		    toplevel.setVisible(true);
		    toplevel.setTitle("My Frame");

        String host = DEFAULT_HOST;
        int port = DEFAULT_PORT;
        //if (argv.length >=1) host = argv[0];
        //if (argv.length >=2) port = Integer.parseInt(argv[1]);
        
        Client client = null;
        
        try {
          client = new Client(host, port);
        }
        catch (Exception e) {
          System.err.println("Client: Couldn't connect to "+host+":"+port);
          System.exit(1);
        }
            
    System.out.println("Client connected to "+host+":"+port);

    // pour lire depuis la console
    BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
    
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
    }
  }*/

}

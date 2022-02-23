# RemoteSwing
The java client implementation with GUI (By java Swing).Check the `../html_swing` and double click the `index.html` for more details of the RemoteSwing documentation.




## How to run:
```
>cd RemoteSwing/src
>make run
```
Then the client GUI will occur.[^1] You could choose one operation in the radiobutton among `RechercherMultimedia`, `RechercherGroup`, `AfficherMultimedia`, `AfficherGroup` and `JouerMultimedia`. Then enter the name of the object you are interested like `group1`(includes `photo1`, `video1`), `photo2`, `photo3`, `photo4`, `photo5`, `video2`, `video3`, and `film1`.[^2] After choosing operation and entering the name, press the ok and watch the response received in the console. There are 3 buttons below which is for the step1 of the TP: First 2 buttons add phrases to the TextArea and the last close the window.

[^1]: The Menus and Tollbars are not implemented with actions (only print what is clicked). This is for future development.

[^2]: Multimedia includes Photo, Video, Film. Please make sure not to mismatch operation and the name you enter. For example, do not choose `RechercherGroup` for `photo2`.

## How to clean
```
make clean
```

## GUI Structure
<img width="1061" alt="GUIdemo" src="https://user-images.githubusercontent.com/49087409/154851287-10ce0f03-63a7-40cc-aa24-0a1450fab65d.png">

## The result demo
<img width="895" alt="return_mes" src="https://user-images.githubusercontent.com/49087409/154851347-ba7f0625-627a-41ed-be95-82e41a87e043.png">

## Some implementations
In the src folderthere are 3 java files (2 essential defined in the Makefile, 1 negligeable for test) in the package clientapp. The `Client.java` is the implementation for the client and `MyFrame.java` is the GUI JFrame where we define some actions for interations.
### JRadioButton for choosing the operation
In the pnlleft, we set 5 radiobuttons[^3] and add them to a ButtonGroup named `buttonGroup`.
The ItemEvent for the radiobuttons are:
```
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
```c

where we pass the operation command to the string `s_cmd`

[^3]: which are `rdo1` to `rdo5` .

### Sending request 
We send request after the `ok` button is clicked. When we choose the operation and enter the name of object, we press the `ok` button. Then the request will be added to the scrollpane at right side and send to the server.
```
        JButton ok = new JButton("Ok");

        ok.addActionListener(e ->{
            s_cmd = s_cmd+" "+txtfield.getText()+"\n"; /**<combine the operation choson with the name of objext to form a complete request */
            System.out.println("Command sent is: "+s_cmd); /**<print the reequest in the console */ 
            txta.append(s_cmd); /**<Add the request command to the TextArea*/
            String response = client.send(s_cmd);  /**<send request and receive response */
            System.out.println("Message returned: "+response);  /**<Print the response in the console */
            s_cmd="";/**<reset the request command */
            //request = s_cmd
        });

```c



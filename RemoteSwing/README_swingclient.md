# RemoteSwing
The java client implementation with GUI (By java Swing).Check the `../html_swing` and double click the `index.html` for more details of the RemoteSwing documentation.




## How to run:
```
>cd RemoteSwing/src
>make run
```
Then the client GUI will occur.[^1] You could choose one operation in the radiobutton among `RechercherMultimedia`, `RechercherGroup`, `AfficherMultimedia`, `AfficherGroup` and `JouerMultimedia`. Then enter the name of the object you are interested like `group1`(includes `photo1`, `video1`), `photo2`, `photo3`, `photo4`, `photo5`, `video2`, `video3`, and `film1`.[^2]

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

## 


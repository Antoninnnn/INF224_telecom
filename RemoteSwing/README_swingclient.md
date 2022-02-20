# RemoteSwing
The java client implementation with GUI (By java Swing).




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


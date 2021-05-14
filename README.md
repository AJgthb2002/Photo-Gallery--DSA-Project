## Photo-Gallery with Image editing tools
```
___   _  _ ____ ___ ____    ____ ____  _    _    ____ ____ _   _ 
| __] |__| |  |  |  |  |    | __ | __| |    |    |___ |__/  \_/ 
|     |  | |__|  |  |__|    |__] |   | |___ |___ |___ |  \   |  
```
```
        00      @                                                            +                                ****
        00     @@                                                            *                              ********
      ******  @@                                                            ***                            **********
     ********@@                                                            *****                          ************
     ********@                                                            ********                        ************
    **********                                                          @  ******  @                       **********
   ************                                                           *******                           ********
   +          +                                                          **********                          ******
   +          +                   ___      ___                         **************                         .  .
   +          +                  (o o)    (o o)                      @****o******o****@                       .  .
   +          +                 (  V  )  (  V  )                          ********                          ++++++++..
   +          +                /--m-m-  /--m-m-                          **********                         ++++++++  .
   +          +                                                        *o***********o*                      ++++++++   .
   ++++++++++++                                                      @****o*******o****@                    ++++++++   .
   ++++++++++++                                                            #######                                    .
        ++                                                                 #######                                  .
        ++                                                                 #######                                 .
       ++++                                                                #######                                .
      ++++++                                                               #######                    ............+......
     ++++++++   
```
This is a group project for the course Data Structures and Algorithms 1 Laboratory (CE 2106). </br>
Aim of the project is to **implement a photo gallery software and simulate the working of some image editing tools like crop, rotate and flip**.
Programming language used: C++

Images are created by initializing matrices with different characters. Each image is of size 20 rows x 20 columns. These are saved in the ImageMatrix.h header file.
Some examples of the images created by us are displayed above.

Every object of Class Image has attributes like the name, size, date of image, rows, columns of image and a character matrix. </br>
Functions that can be performed on each image under the edit menu are: </br>
**`1. Cropping ` &nbsp; &nbsp; `2. Left rotation (90 deg) `&nbsp; &nbsp; `3. Right rotation (90 deg) `&nbsp; &nbsp; `4. Flip (mirror image)  ` &nbsp; &nbsp; `5. Rename image `**

The Gallery class is a doubly circular linked list. All the image objects are inserted in it, at the beginning of the program. </br>
Functions of the Gallery class are: </br>
**`1. View previous image ` &nbsp; &nbsp; `2. View next image `&nbsp; &nbsp; `3. Edit image `&nbsp; &nbsp; `4. View image details  ` </br>
`5. Make a copy of the image ` &nbsp; &nbsp; `6. Delete image `**

The latest added image appears first when the Gallery is opened by the users. They can naviagte through all images by using the view previous or next options.
They can choose to edit the currently displayed image, wherein they can perform multiple editing operations on it. All the changes get saved automatically. Users can also view the details of currently displayed image, make a copy of it or delete it.

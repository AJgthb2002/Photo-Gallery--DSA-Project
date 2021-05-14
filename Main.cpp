#include<iostream>
#include "Gallery.h"
#include "Image.h"
#include "ImageMatrix.h"

using namespace std;

int main()
{
    
    ImageMatrix matobj;                                                     // create an object of class ImageMatrix

    Image* img1 = new Image(20, 20, "alien", "08/05/2021", 400);            // create a new Image object
    img1->accept(matobj.mat1);                                              // copy mat1 into matrix of Image object

    Image* img2 = new Image(20, 20, "bird", "08/05/2021", 400);             // create a new Image object
    img2->accept(matobj.mat2);                                              // copy mat2 into matrix of Image object

    Image* img3 = new Image(20, 20, "arrow", "08/05/2021", 400);
    img3->accept(matobj.mat3);

    Image* img4 = new Image(20, 20, "cat", "12/05/2021", 400);
    img4->accept(matobj.mat4);

    Image* img5 = new Image(20, 20, "christmas tree", "11/05/2021", 400);
    img5->accept(matobj.mat5);

    Image* img6 = new Image(20, 20, "hot air balloon", "11/05/2021", 400);
    img6->accept(matobj.mat6);

    Image* img7 = new Image(20, 20, "ice cream", "12/05/2021", 400);
    img7->accept(matobj.mat7);

    Image* img9 = new Image(20, 20, "2 birds", "12/05/2021", 400);
    img9->accept(matobj.mat9);

    Gallery myGallery;                                     // create object of Gallery class
    myGallery.insert(img2);                                // insert an Image object at the beginning of linked list
    myGallery.insert(img1); 
    myGallery.insert(img3);
    myGallery.insert(img4);
    myGallery.insert(img5);
    myGallery.insert(img6);
    myGallery.insert(img7);
    myGallery.insert(img9);
    
    int gallery_choice;                                   // variable to store the option chosen by user


    string gallery_menu = "\t\t\t\t\t\t\t\t < 1. View prev                       2. View next >\n"
                          "\t\t\t\t\t\t\t\t                 3. Edit Image                      \n"
                          "\t\t\t\t\t\t\t\t                 4. Make a copy                     \n"
                          "\t\t\t\t\t\t\t\t                 5. Delete Image                    \n"
                          "\t\t\t\t\t\t\t\t                 6. View Image details              \n"
                          "\t\t\t\t\t\t\t\t                 7. Exit                            \n\t\t\t\t\t\t\t\t>>";

    string heading =
        "\t\t\t\t\t\t\t ___   _  _ ____ ___ ____    ____ ____  _    _    ____ _____   _ \n"
        "\t\t\t\t\t\t\t | __] |__| |  |  |  |  |    | __ | __| |    |    |___ |__/ \\_/  \n"
        "\t\t\t\t\t\t\t |     |  | |__|  |  |__|    |__] |   | |___ |___ |___ | \\   |   \n";





    cout <<heading<< endl;   // display the title

    if (myGallery.open_gallery() == 1)                       // open_gallery==1 indicates that head is not null
    do {
        if (myGallery.count <= 0)                            // check the number of images present in the linked list
        {
            cout << "\nGallery is empty. No images found!" << endl;
            break;
        }

        cout << "\n" << gallery_menu;            // display gallery menu options
        cin >> gallery_choice;
        switch (gallery_choice)
        {
        case 1: myGallery.view_prev();  break;       
        case 2: myGallery.view_next(); break;
        case 3: myGallery.edit(); break;
        case 4: myGallery.copy_img(); break;
        case 5: myGallery.delete_img(); break;
        case 6: myGallery.view_details(); break;
        case 7: break;
        }
    } while (gallery_choice != 7);             // repeat the loop till the user does not select option 7 i.e. exit

    return 0;
}

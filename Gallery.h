#pragma once
#include "Image.h"

class Gallery       //DCLL of Image class objects
{
    Image* head;     // points to the latest added image in gallery
    Image* current;  // points to the selected image

public:
    int count;  // keeps track of number of images present in the gallery

    Gallery()
    {
        head = current = NULL;
        count = 0;
    }

    void insert(Image* im); 
    int open_gallery();
    void view_next(); 
    void view_prev();
    void delete_img(); 
    void copy_img(); 
    void edit(); 
    void view_details();
    void clear_screen(); 
};
#pragma once
#include<string>
using namespace std;
class Image
{

    int r, c;            // stores number of rows and cols of the image
    string name;
    string date;
    float size;
    char mat[20][20];

    Image* next;        // points to the next image in gallery
    Image* prev;        // points to the previous image in gallery

public:

    Image(int rows, int cols, string nm, string dt, int sz)
    {
        r = rows;
        c = cols;
        name = nm;
        date = dt;
        size = sz;
        next = NULL;
        prev = NULL;

    }

    void accept(char matrix[20][20]);  
    void rotate_right(); 
    void rotate_left(); 
    void flip(); 
    void crop(); 
    void display();
    void rename_img(); 
    void rev(char c[]); 
    void clear_screen();

    friend class Gallery;
};
#include<iostream>
#include "Gallery.h"

using namespace std;

void Gallery::insert(Image* im)  // inserts image at the beginning of linked list
{
    if (head == NULL)            // check if list is empty
    {
        im->next = im;          //make prev as well as next ptr point on the same image
        im->prev = im;
        head = im;            //  make head point on this new image
        count++;             // increments the count of images present in list
    }

    // if some images are already present in list, insert the new image at the beginning.
    else
    {
        im->next = head;
        im->prev = head->prev;
        head->prev->next = im;
        head->prev = im;
        head = im;            // make head point on the new image.
        count++;             // increments the count of images present in list
    }
}

int Gallery::open_gallery()
{
    if (head == NULL)    // check if list is empty
    {
        cout << "\n\t\t\t\t\t\t\t\t\tYour Gallery is empty. No images found!" << endl;
        return 0;
    }

    if (current == NULL)  // check if any image is selelcted
        current = head;  // selects the first image
    current->display();  // display the selected image
    return 1;
}

void Gallery::copy_img()
{
    // create a new Image object having the same attributes as the currently selected image.
    Image* copy = new Image(current->r, current->c, (current->name + "(copy)"), current->date, current->size);
    copy->accept(current->mat);

    // insert this image copy in the list, after the selected image
    copy->prev = current;
    copy->next = current->next;
    current->next->prev = copy;
    current->next = copy;

    clear_screen();
    cout << "\n\t\t\t\t\t\t\t\t\tImage copy created successfully!" << endl;

    current = current->next;   // select the next image i.e. the copy
    current->display();        // display the copy of image
}

void Gallery::delete_img()
{ 
    if (head == NULL)   // check if list is empty
    {
        cout << "\n\t\t\t\t\t\t\t\t\tYour Gallery is empty. No images found!" << endl;
    }
    else
    {
        Image* temp;     // create a temp pointer which points to an Image object
        if (current == head)  // delete the head node
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            temp = head;
            current = current->next;
            head = head->next;
            count--;
            delete temp;
            clear_screen();
            cout << "\n\t\t\t\t\t\t\t\t\t\t    Image deleted!\n";
            current->display();  // display the next image in Gallery
        }
        else   // delete a node other than head node
        {
            current->next->prev = current->prev;
            current->prev->next = current->next;
            temp = current;
            if (current == head)               // first node is deleted
                head = head->next;
            current = current->next;
            clear_screen();
            cout << "\n\t\t\t\t\t\t\t\t\t\t    Image deleted!\n";
            count--;
            if (count > 0)
                current->display();
            delete temp;
        }
        
    }


}

void Gallery::view_next() // moves pointer to next image and displays it
{
    current = current->next;
    clear_screen();
    current->display();
}
void Gallery::view_prev() // moves pointer to previous image and displays it
{
    current = current->prev;
    clear_screen();
    current->display();
}

void Gallery::edit()
{
    int edit_choice;   // stores the option selected by user
    do {
  
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t*** Edit Menu ***" << endl;
        cout << "\t\t\t\t\t\t\t\t1.Rotate Left\t\t2.Rotate Right\t\t3.Flip (Mirror Image)\n\t\t\t\t\t\t\t\t4.Crop\t\t\t5.Rename\t\t6.Back to Gallery\n\t\t\t\t\t\t\t\t>>";
        cin >> edit_choice;
        switch (edit_choice)
        {
        case 1: current->rotate_left(); break;
        case 2: current->rotate_right(); break;
        case 3: current->flip(); break;
        case 4: current->crop(); break;
        case 5: current->rename_img(); break;
        case 6: clear_screen(); current->display(); break;
        default: cout << "\t\t\t\t\t\t\t\tInvalid choice!" << endl;
        }
    } while (edit_choice != 6);        // repeat the loop until the user selects option 6 i.e. return back
      
}


void Gallery::view_details()     // prints all the details of the selected image
{
    clear_screen();
    cout << "\n\t\t\t\t\t\t\t\t\tImage details:";
    cout << "\n\t\t\t\t\t\t\t\t\t-------------------------------------";
    cout << "\n\t\t\t\t\t\t\t\t\tName: " << current->name << ".jpg";
    cout << "\n\t\t\t\t\t\t\t\t\tDate: " << current->date;
    cout << "\n\t\t\t\t\t\t\t\t\tSize: " << current->size << "B";
    cout << "\n\t\t\t\t\t\t\t\t\t-------------------------------------";
    cout << "\n";
    current->display();
}

void Gallery::clear_screen()
{
    cout << "\033[2J\033[1;1H";
}

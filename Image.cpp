#include<iostream>
#include "Image.h"

using namespace std;

void Image::accept(char matrix[20][20])      // copies the elements of parameter matrix into mat
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            mat[i][j] = matrix[i][j];
        }
    }
}

void Image::display()                      // displays the matrix of selected image
{
    for (int i = 0; i < r; i++)
    {
        cout << "\t\t\t\t\t\t\t\t\t";
        for (int j = 0; j < c; j++)
        {
            cout <<mat[i][j]<<" ";
        }
        cout << "\n";
    }
}

void Image::rename_img()                  // inputs a new name from the user and renames the selected image
{
    string new_name;
    cout << "\n\t\t\t\t\t\t\t\t\tCurrent name: " << name << endl;
    cout << "\n\t\t\t\t\t\t\t\t\tEnter new name: ";
    cin >> new_name;
    name = new_name;
    clear_screen();
    cout << "\n\t\t\t\t\t\t\t\t\tImage renamed successfully!" << endl;
    display();
}

void Image::crop()   // crops the image according to no. of rows/columns entered by user and displays the cropped image
{
    int crop_side;   // stores the side from which the user wants to crop image (top/bottom/left/right)
    int crop_cols;  // stores the no. of columns the user wants to crop
    int crop_rows;  // stores the no. of rows the user wants to crop

    do {
        cout << "\n\t\t\t\t\t\t\t\t\tCrop from: 1.Top  2.Right  3. Bottom  4. Left" << endl;
        cout << "\n\t\t\t\t\t\t\t\t\t(Enter 0 to return back to Edit menu)" << "\n\t\t\t\t\t\t\t\t";
        cin >> crop_side;
        switch (crop_side)
        {
        case 0: break;
        case 1: {
            cout << "\n\t\t\t\t\t\t\t\t\tNo. of rows to crop? (0 to" << r - 1 << ") ";
            cin >> crop_rows;
            char cropped_matrix[20][20];
            for (int x = 0; x < 20; x++) //iterate over rows  
                for (int y = 0; y < 20; y++)  //iterate over cols
                    cropped_matrix[x][y] = ' ';  // set all elements in cropped matrix to ' '

            for (int i = crop_rows; i < 20; i++)
                for (int j = 0; j < 20; j++)
                    cropped_matrix[i - crop_rows][j] = mat[i][j]; // copy the characters of remaining rows into cropped matrix

            accept(cropped_matrix);
            r = r - crop_rows;  // reduce the number of rows in Image after cropping
            size = r * c;       // reset the size of image according to current no. rows and colums
            clear_screen();
            display();          // display cropped image
            break;
        }

        case 2: {
            cout << "\n\t\t\t\t\t\t\t\t\tNo. of columns to crop? (0 to" << c - 1 << ") ";
            cin >> crop_cols;
            c = c - crop_cols;  // reduce the number of columns in Image after cropping
            size = r * c;       // reset the size of image according to current no. rows and colums
            clear_screen();
            display();          // display cropped image
            break;
        }

        case 3: {
            cout << "\n\t\t\t\t\t\t\t\t\tNo. of rows to crop? (0 to" << r - 1 << ") ";
            cin >> crop_rows;
            r = r - crop_rows;
            size = r * c;
            clear_screen();
            display();
            break;
        }

        case 4: {
            cout << "\n\t\t\t\t\t\t\t\t\tNo. of columns to crop? (0 to" << c - 1 << ") ";
            cin >> crop_cols;
            char cropped_matrix[20][20];
            for (int x = 0; x < 20; x++) //rows  
                for (int y = 0; y < 20; y++)  //cols
                    cropped_matrix[x][y] = ' ';  // set all elements in cropped matrix to ' '

            for (int i = crop_cols; i < 20; i++) //cols
                for (int j = 0; j < 20; j++) //rows
                    cropped_matrix[j][i - crop_cols] = mat[j][i]; // copy the characters of remaining cols into cropped matrix

            accept(cropped_matrix);
            c = c - crop_cols;
            size = r * c;
            clear_screen();
            display();
            break;
        }

        default: cout << "\n\t\t\t\t\t\t\t\t\tInvalid choice!" << endl;
        }
    } while (crop_side != 0);
}

void Image::rotate_left()
{
    char rotated_matrix[20][20];
    for (int x = 0; x < 20; x++) //rows  
    {
        for (int y = 0; y < 20; y++)  //cols
        {
            rotated_matrix[x][y] = ' ';  // set all elements in rotated mat to ' '
        }
    }

    for (int x = 0; x < 20; x++) //rows                  
    {
        for (int y = 0; y < 20; y++)  //cols
        {
            rotated_matrix[x][y] = mat[y][c - 1 - x];  // store elements from mat at rotated position in rotated matrix
        }
    }

    accept(rotated_matrix);  // save that rotated mat in original

    int temp;    // interchange values of rows and cols as the matrix is rotated
    temp = r;
    r = c;
    c = temp;
    clear_screen();
    display();  // display the rotated matrix
}

void Image::rotate_right()
{
    char rotated_matrix[20][20];
    for (int x = 0; x < 20; x++) //rows  
    {
        for (int y = 0; y < 20; y++)  //cols
        {
            rotated_matrix[x][y] = ' ';  // set all elements in rotated mat to ' '
        }
    }

    for (int x = 0; x < 20; x++) //rows
    {
        for (int y = 0; y < 20; y++)  //cols
        {
            rotated_matrix[x][y] = mat[r - y - 1][x];  // store elements from mat at rotated position in rotated matrix
        }
    }
    accept(rotated_matrix);  // save that rotated mat in original

    int temp;    // interchange values of rows and cols as the matrix is rotated
    temp = r;
    r = c;
    c = temp;
    clear_screen();
    display();  // display the rotated matrix
}
void Image::rev(char ca[])   // reverses the elements of the row passed in as parameter
{
    for (int i = 0; i < c/2; i++) {
        char temp = ca[i];
        ca[i] = ca[c - i - 1];
        ca[c - i - 1] = temp;
    }
}

void Image::flip()
{
    char temp[20][20];

    for (int i = 0; i < r; i++) 
    {
        rev(mat[i]); // reverses one row
        for (int j = 0; j < c; j++)
        {
            temp[i][j] = mat[i][j];
        }
    }
    accept(temp);
    clear_screen();
    display();

}

void Image::clear_screen()
{
    cout << "\033[2J\033[1;1H";
}


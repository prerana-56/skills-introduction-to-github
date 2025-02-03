/*Imagine a publishing company which does marketing for book and audio cassette
versions. Create a class publication that stores the title (a string) and price (type float) of
a publication.
From this class derive two classes: book, which adds a page count (type int), and tape,
which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape classes, allows user to enter data
and displays the data members. If an exception is caught, replace all the data member
values with zero values.*/

#include<iostream>
using namespace std;
class Publication{
    protected:
    string title;
    float price;
    void inp_g(){
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        
        
    }
    void display_g(){
        cout << "Title = " << title << "\n";
        cout << "Price = " << price << " rs" << "\n";
    }
    

};
class Book:public Publication{   
    protected:
    int page_count;
    public:
    void set(string title, float price, int page_count){
        this->title = title;
        this->price = price;
        this->page_count = page_count;
    }
    bool check(){
        if(price< 0 || page_count<0){
            return false;
        }
        else{
            return true;
        }
    }
    void inp(){
        bool flag = false;
        try{ 
            cout << "Enter details of book: \n";
            inp_g();
            cout << "Enter page count: ";
            cin >> page_count;
            if(cin.fail())
            throw flag;
            if(!this->check())
            throw flag;
            
        }
        catch(bool flag){
            title = "--";
            price = 0;
            page_count = 0;
        }
    }
    void display(){
        cout << "Details of the book: " << "\n";
        display_g();
        cout << "Page count = " << page_count << "\n";
    }
    
};
class Tape:public Publication
{
    protected:
    float minutes;
    public:
    bool check(){
        if(price< 0 || minutes<0){
            return false;
        }
        else{
            return true;
        }
    }
    void set(string title, float price, float minutes){
        this->title = title;
        this->price = price;
        this->minutes = minutes;
    }
    void inp(){
        bool flag = false;
        try{ 
            cout << "Enter details of audio cassette: \n";
            inp_g();
            cout << "Enter playtime: ";
            cin >> minutes;
            if(cin.fail())
            throw flag;
            if(!this->check())
            throw flag;
            
        }
        catch(bool flag){
            title = "--";
            price = 0;
            minutes = 0;
        }

    }
    void display(){
        cout << "Details of the audio casette: " << "\n";
        display_g();
        cout << "Playtime =  " << minutes << " minutes" << "\n";
    }
};
int main(){
    string rollno;
    cout << "Name: Prerana Pokarna " <<endl;
    cout << "Batch: S11 " << endl;
    cout << "Roll Number:  "<< endl;
    cin >> rollno;
    Book b1;
    Tape t1;
    b1.inp();
    t1.inp();
    b1.display();
    t1.display();
    return 0;
}

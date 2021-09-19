/*
Imagine a publishing company which does marketing for book and audiocassette versions.
Create a class publication that stores the title (a string) and price (type float) of a publication.
From this class derive two classes: book, which adds a page count (type int), and tape, which
adds a playing time in minutes (type float).
Write a program that instantiates the book and tape classes, allows user to enter data and
displays the data members. If an exception is caught, replace all the data member values with
zero values
*/

#include <iostream>

using namespace std;

class Publication {
    protected:
        char title[60];
    float price;
};

class Book: public Publication {
    private: int page_count;
    public: void get() {
        try {
            cout << "\n Enter Book Title & price = ";
            cin >> title >> price;
            cout << "\n Enter Page Count for Book = ";
            cin >> page_count;
            if (page_count <= 0)
                throw 1;
        } catch (int i) {
            if (i == 1) {
                cout << "\n You Entered Invalid Page Count";
                page_count = 0;
                cout << "\npage_count= " << page_count;

                cout << "\n Enter page count again";
                cin >> page_count;
            }

        }
    }
    void put() {
        cout << "\n Book Details are:" << endl;
        cout << "\n \t BOOK TITLE \t\t PRICE \t\t PAGE COUNT";
        cout << "\n \t" << title << "\t\t" << price << "\t\t" << page_count;
    }
};

class Tape: public Publication {
    private: float playing_time;
    public: void get1() {
        cout << "\n Enter Tape Title & price = ";
        cin >> title >> price;
        cout << "\n Playing Time in Minutes for Tape = ";
        cin >> playing_time;
    }
    void put1() {
        cout << "\n\n Tape Details are:" << endl;
        cout << "\n \t TAPE TITLE \t\t PRICE \t\t PLAYING TIME";
        cout << "\n \t" << title << "\t\t" << price << "\t\t" << playing_time;
    }
};
int main() {
    Book B;
    Tape T;
    cout << "\n Enter Details for Book : ";
    B.get();
    cout << "\n Enter Details for Tape : ";
    T.get1();
    // Details are
    B.put();
    T.put1();

    return 0;
}

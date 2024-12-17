// Imagine a publishing company which does marketing for book and audio cassette versions.
// Create a class publication that stores the title (a string) and price (type float) of publications. From this class derive two classes:
// book which adds a page count (type int) and tape which adds a playing time in minutes (type float). 
// Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. If an exception is caught, replace all the data member values with zero values.

#include<iostream> 
using namespace std; 

class publication { 
    private: 
        string title; 
        float price; 
    public: 
        void add() { 
            cout << "\nEnter the Publication information: " << endl; 
            cout << "Enter Title of the Publication: "; 
            cin.ignore(); 
            getline(cin, title); 
            cout << "Enter Price of Publication: "; 
            cin >> price; 
                } 

        void display() { 
            cout << "\n--------------------------------------------------"; 
            cout << "\nTitle of Publication: " << title; 
            cout << "\nPublication Price: " << price; 
            } 
}; 

class book : public publication { 
    private: 
        int page_count; 
    public: 
        void add_book() { 
            try { 
                add(); 
                cout << "Enter Page Count of Book: "; 
                cin >> page_count; 
                if (page_count <= 0) { 
                    throw page_count; 
                } 
            } catch(...) { 
                cout << "\nInvalid Page Count!!!"; 
                page_count = 0; 
            } 
        } 

    void display_book() { 
        display(); 
            cout << "\nPage Count: " << page_count; 
            cout << "\n--------------------------------------------------\n"; 
        } 
}; 

class tape : public publication { 
    private: 
        float play_time; 
    public: 
        void add_tape() { 
            try { 
                add(); 
                cout << "Enter Play Duration of the Tape (in minutes): "; 
                cin >> play_time; 
                if (play_time <= 0) { 
                    throw play_time; 
                } 
            } catch(...) { 
                cout << "\nInvalid Play Time!!!"; 
                play_time = 0; 
            } 
        } 

        void display_tape() { 
            display(); 
            cout << "\nPlay Time: " << play_time << " min"; 
            cout << "\n--------------------------------------------------\n"; 
            } 
}; 

int main() { 
    book b1[10]; 
    tape t1[10]; 
    int ch, b_count = 0, t_count = 0; 

    do { 
    cout << "\nPUBLICATION DATABASE SYSTEM"; 
    cout << "\n1. Add Information to Books"; 
    cout << "\n2. Add Information to Tapes"; 
    cout << "\n3. Display Books Information"; 
    cout << "\n4. Display Tapes Information"; 
    cout << "\n5. Exit"; 
    cout << "\nEnter your choice: "; 
    cin >> ch; 
 
        switch(ch) { 
            case 1: 
                b1[b_count].add_book(); 
                b_count++; 
                break; 
            case 2: 
                t1[t_count].add_tape(); 
                t_count++; 
                break; 
            case 3: 
                for (int j = 0; j < b_count; j++) { 
                    b1[j].display_book(); 
                } 
                break; 
            case 4: 
                for (int j = 0; j < t_count; j++) { 
                    t1[j].display_tape(); 
                } 
                break; 
            case 5: 
                cout<<"Thanks for using this program!";
                exit(0); 
            default: 
                cout<<"Enter valid choice!";
        } 
    } while (ch != 5); 
 
    return 0; 
}

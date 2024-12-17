/*Develop a program in C++ to create a database of student’s information system containingthe following information: Name,
roll number, Class, Division, Date of Birth, Blood group, contact address, Telephone number, Driving license no. and
other. Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-
new and delete as well as exception*/

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dob;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string email;
    string drivingLicenseNumber;

public:
    Student() : rollNumber(-1), division('\0') {}

    void getData();
    void displayData() const;
    bool validatePhoneNumber() const { return telephoneNumber.length() == 10; }
    bool validateEmail() const { return email.size() > 10 && email.substr(email.size() - 10) == "@gmail.com"; }
    void modifyData();
    void deleteData() { rollNumber = -1; } // Mark record as deleted
    int getRollNumber() const { return rollNumber; }
};

void Student::getData() {
    cout << "Enter Roll No: ";
    cin >> rollNumber;
    cin.ignore(); // Clear buffer

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Class: ";
    cin >> studentClass;

    cout << "Enter Division: ";
    cin >> division;

    cout << "Enter Date of Birth (DD/MM/YYYY): ";
    cin >> dob;

    cout << "Enter Blood Group: ";
    cin >> bloodGroup;

    cin.ignore();
    cout << "Enter Contact Address: ";
    getline(cin, contactAddress);

    do {
        cout << "Enter Telephone Number: ";
        cin >> telephoneNumber;
        if (!validatePhoneNumber()) {
            cout << "Invalid phone number. It should be exactly 10 digits.\n";
        }
    } while (!validatePhoneNumber());

    do {
        cout << "Enter Email Address: ";
        cin >> email;
        if (!validateEmail()) {
            cout << "Invalid email. It must end with @gmail.com.\n";
        }
    } while (!validateEmail());

    cout << "Enter Driving License Number: ";
    cin >> drivingLicenseNumber;
}

void Student::displayData() const {
    if (rollNumber == -1) {
        cout << "This record has been deleted.\n";
        return;
    }

    cout << "Roll No: " << rollNumber << "\n";
    cout << "Name: " << name << "\n";
    cout << "Class: " << studentClass << "\n";
    cout << "Division: " << division << "\n";
    cout << "Date of Birth: " << dob << "\n";
    cout << "Blood Group: " << bloodGroup << "\n";
    cout << "Contact Address: " << contactAddress << "\n";
    cout << "Telephone Number: " << telephoneNumber << "\n";
    cout << "Email: " << email << "\n";
    cout << "Driving License Number: " << drivingLicenseNumber << "\n";
}

void Student::modifyData() {
    int choice;
    cout << "Modify Menu:\n1. Name\n2. Class\n3. Division\n4. Date of Birth\n5. Blood Group\n6. Contact Address\n7. Telephone Number\n8. Email\n9. Driving License\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 1:
        cout << "Enter new Name: ";
        getline(cin, name);
        break;
    case 2:
        cout << "Enter new Class: ";
        cin >> studentClass;
        break;
    case 3:
        cout << "Enter new Division: ";
        cin >> division;
        break;
    case 4:
        cout << "Enter new DOB: ";
        cin >> dob;
        break;
    case 5:
        cout << "Enter new Blood Group: ";
        cin >> bloodGroup;
        break;
    case 6:
        cout << "Enter new Contact Address: ";
        cin.ignore();
        getline(cin, contactAddress);
        break;
    case 7:
        do {
            cout << "Enter new Telephone Number: ";
            cin >> telephoneNumber;
            if (!validatePhoneNumber()) {
                cout << "Invalid phone number.\n";
            }
        } while (!validatePhoneNumber());
        break;
    case 8:
        do {
            cout << "Enter new Email: ";
            cin >> email;
            if (!validateEmail()) {
                cout << "Invalid email.\n";
            }
        } while (!validateEmail());
        break;
    case 9:
        cout << "Enter new Driving License: ";
        cin >> drivingLicenseNumber;
        break;
    default:
        cout << "Invalid choice!\n";
    }
}

int main() {
    Student students[10];
    int n = 0, choice;

    do {
        cout << "\nMenu:\n1. Add Student\n2. Display All Students\n3. Modify Student\n4. Delete Student\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (n < 10) {
                students[n].getData();
                n++;
            } else {
                cout << "Student limit reached!\n";
            }
            break;
        case 2:
            for (int i = 0; i < n; i++) {
                cout << "\nStudent " << (i + 1) << ":\n";
                students[i].displayData();
            }
            break;
        case 3: {
            int rollNumber;
            cout << "Enter Roll Number to Modify: ";
            cin >> rollNumber;
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (students[i].getRollNumber() == rollNumber) {
                    students[i].modifyData();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found!\n";
            break;
        }
        case 4: {
            int rollNumber;
            cout << "Enter Roll Number to Delete: ";
            cin >> rollNumber;
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (students[i].getRollNumber() == rollNumber) {
                    students[i].deleteData();
                    found = true;
                    cout << "Student deleted successfully.\n";
                    break;
                }
            }
            if (!found) cout << "Student not found!\n";
            break;
        }
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

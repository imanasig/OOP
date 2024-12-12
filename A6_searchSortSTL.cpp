/*Write C++ program using STL for sorting and searching user defined records such as personal records (Name, DOB, Telephone number etc.) using vectorcontainer.*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Person {
public:
    string fullName;
    int phoneNumber;
    string dob;

    bool operator==(const Person& other) const {
        return phoneNumber == other.phoneNumber;
    }
    bool operator<(const Person& other) const {
        return phoneNumber < other.phoneNumber;
    }
};

vector<Person> records;

void displayRecord(const Person& record);
void displayAllRecords();
void addRecord();
void searchRecord();
void deleteRecord();
bool compareByDob(const Person& p1, const Person& p2);

int main() {
    int choice;
    do {
        cout << "\n* * * * * Menu * * * * *";
        cout << "\n1. Add Record";
        cout << "\n2. Display All Records";
        cout << "\n3. Search Record";
        cout << "\n4. Sort Records by DOB";
        cout << "\n5. Delete Record";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addRecord();
            break;
        case 2:
            displayAllRecords();
            break;
        case 3:
            searchRecord();
            break;
        case 4:
            sort(records.begin(), records.end(), compareByDob);
            cout << "\nSorted by Date of Birth:\n";
            displayAllRecords();
            break;
        case 5:
            deleteRecord();
            break;
        case 6:
            cout << "\nExiting program. Goodbye!\n";
            return 0;
        default:
            cout << "\nInvalid choice! Please try again.";
        }
    } while (true);
    return 0;
}

void addRecord() {
    Person newRecord;
    cin.ignore(); // Clear input buffer
    cout << "\nEnter Full Name: ";
    getline(cin, newRecord.fullName);
    cout << "Enter Phone Number: ";
    cin >> newRecord.phoneNumber;
    cout << "Enter Date of Birth (DD/MM/YYYY): ";
    cin >> newRecord.dob;
    records.push_back(newRecord);
}

void displayAllRecords() {
    if (records.empty()) {
        cout << "\nNo records available.\n";
        return;
    }
    for_each(records.begin(), records.end(), displayRecord);
}

void displayRecord(const Person& record) {
    cout << "\nName: " << record.fullName;
    cout << "\nPhone Number: " << record.phoneNumber;
    cout << "\nDate of Birth: " << record.dob << "\n";
}

void searchRecord() {
    int searchPhone;
    cout << "\nEnter Phone Number to search: ";
    cin >> searchPhone;

    auto it = find_if(records.begin(), records.end(), [&](const Person& p) {
        return p.phoneNumber == searchPhone;
    });

    if (it != records.end()) {
        cout << "\nRecord Found:\n";
        displayRecord(*it);
    } else {
        cout << "\nRecord Not Found!";
    }
}

void deleteRecord() {
    int deletePhone;
    cout << "\nEnter Phone Number to delete: ";
    cin >> deletePhone;

    auto it = find_if(records.begin(), records.end(), [&](const Person& p) {
        return p.phoneNumber == deletePhone;
    });

    if (it != records.end()) {
        records.erase(it);
        cout << "\nRecord Deleted!";
    } else {
        cout << "\nRecord Not Found!";
    }
}

bool compareByDob(const Person& p1, const Person& p2) {
    return p1.dob < p2.dob;
}

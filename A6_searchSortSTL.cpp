/*Write C++ program using STL for sorting and searching user defined records such as personal records (Name, DOB, Telephone number etc.) using vectorcontainer.*/

#include <iostream>
#include <vector>
#include <algorithm> // For sort and find_if
#include <string>

using namespace std;

// PersonalRecord class to store personal details
class PersonalRecord {
public:
    string name;
    string dob;        // Date of Birth
    string phoneNumber;

    // Constructor
    PersonalRecord(string name, string dob, string phoneNumber)
        : name(name), dob(dob), phoneNumber(phoneNumber) {}

    // Display method
    void display() const {
        cout << "Name: " << name << ", DOB: " << dob << ", Phone: " << phoneNumber << endl;
    }

    // Operator overload to compare two records for sorting
    bool operator<(const PersonalRecord& other) const {
        return name < other.name; // Sort by name
    }
};

// Function to display all records
void displayRecords(const vector<PersonalRecord>& records) {
    if (records.empty()) {
        cout << "No records to display.\n";
        return;
    }
    cout << "\n--- Personal Records ---\n";
    for (auto it = records.begin(); it != records.end(); ++it) {
        it->display();
    }
    cout << "-------------------------\n";
}

// Simplified function to search for a record by name
void searchRecord(const vector<PersonalRecord>& records, const string& searchName) {
    auto it = find_if(records.begin(), records.end(), [&](const PersonalRecord& record) {
        return record.name == searchName;
    });

    if (it != records.end()) {
        it->display();
    } else {
        cout << "Record not found.\n";
    }
}

int main() {
    vector<PersonalRecord> records; // Vector to store personal records
    int choice;
    string name, dob, phoneNumber;

    do {
        cout << "\n--- Personal Record Management ---\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Sort Records by Name\n";
        cout << "4. Search Record by Name\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
        case 1:
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Date of Birth (DD-MM-YYYY): ";
            getline(cin, dob);
            cout << "Enter Phone Number: ";
            getline(cin, phoneNumber);
            records.emplace_back(name, dob, phoneNumber); // Add record to vector
            cout << "Record added successfully.\n";
            break;

        case 2:
            displayRecords(records); // Display all records
            break;

        case 3:
            sort(records.begin(), records.end()); // Sort using operator
            cout << "Records sorted by name.\n";
            break;

        case 4:
            cout << "Enter name to search: ";
            getline(cin, name);
            searchRecord(records, name); // Search for a record
            break;

        case 5:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}


    

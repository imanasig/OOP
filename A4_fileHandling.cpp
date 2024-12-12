/*Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and read the information from the file..*/

#include<iostream> 
#include<fstream> 
using namespace std; 

class Employee {

	string Name; 
	int ID; 
	double salary; 

public:
	void accept() { 
		cin.ignore(); 
		cout<<"Name: ";
		getline(cin, Name); 
		cout<<"enter your ID";
		cin >> ID;
		cout<<"enter your salary"; 
		cin >> salary; 
	} 

	void display() { 
		cout << "Name=" << Name << " Roll=" << ID << endl; 
	} 
}; 

int main() { 
	Employee empArr[5]; 
	fstream file; 
	int i, numRecords; 

	file.open("employee.txt", ios::out); 

	cout << "how many records you want: "; 
	cin >> numRecords; 

	//for adding elements in file
	for(i = 0; i < numRecords; i++) { 
	empArr[i].accept(); 
	file.write((char*)&empArr[i], sizeof empArr[i]); 
	} 

	file.close(); 
	file.open("employee.txt", ios::in); 

	//for displaying file
	for(i = 0; i < numRecords; i++) { 
	file.read((char*)&empArr[i], sizeof empArr[i]); 
	empArr[i].display(); 
	} 

	file.close(); 
	return 0; 
}

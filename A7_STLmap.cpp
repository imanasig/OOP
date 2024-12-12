Write a program in C++ to use map associative container. The keys will be the names of states and the values will be the populations of the states. When the program runs, the user is prompted to type the name of a
state. The program then looks in the map, using the state name as an index and returns the population of it

#include <map> 
#include <iostream> 
#include <string> 
using namespace std; 

int main() { 

map<string, long long> populationMap; 

	populationMap.insert({"Delhi", 193}); 
	populationMap.insert({"Karnataka", 1123}); 
	populationMap.insert({"Maharashtra", 1339}); 
	populationMap.insert({"Telangana", 129}); 
	populationMap.insert({"Tamil Nadu", 1187}); 
	populationMap.insert({"Gujarat", 234}); 
	populationMap.insert({"Rajasthan", 170}); 

	cout << "Size of population Map: " << populationMap.size() << endl; 

	for (const auto& entry : populationMap) { 
		cout << entry.first << ": " << entry.second << " million" << endl; 
	} 

	string state; 
	cout << "\nEnter the name of a state: "; 
	getline(cin, state); 

	if (populationMap.find(state) != populationMap.end()) { 
		cout << state << "'s population is " << populationMap[state] << " million." << endl; 
	} else { 
		cout << "State not found." << endl; 
	} 

return 0;
}

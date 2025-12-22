#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

// Class that handles Loading the grocery items and keeping track of how many times each one appears
class ItemTracker {
private:
	map<string, int> itemFrequency;

public:
	// Loads all the items from the input file and fills the map
	void LoadData() {
		ifstream inputFile("CS210_Project_Three_Input_File.txt");
		string item;

		// check if the file opened correctly
		if (!inputFile.is_open()) {
			cout << "ERROR: Could not open input file." << endl;
			return;
		}

		// read items one by one and update the map count
		while (inputFile >> item) {
			itemFrequency[item]++;
		}
		inputFile.close();

		// write the frequency data to a backup file
		ofstream outFile("frequency.dat");
		for (auto& pair : itemFrequency) {
			outFile << pair.first << " " << pair.second << endl;
		}
		outFile.close();
	}

	// return how many times an item shows up
	int GetItemFrequency(const string& item) {
		if (itemFrequency.find(item) != itemFrequency.end()) {
			return itemFrequency.at(item);
		}
		return 0; // item is not in the list
	}

	// print all items and their counts

	void PrintAllFrequencies() {
		for (auto& pair : itemFrequency) {
			cout << pair.first << " " << pair.second << endl;
		}
	}

	// print a simple histogram using stars
	void PrintHistorgram() {
		for (auto& pair : itemFrequency) {
			cout << pair.first << " ";
			for (int i = 0; i < pair.second; i++) {
				cout << "*"; // print stars based on count
			}
			cout << endl;
		}
	}
};

int main() {
	ItemTracker tracker;   // object that handles all item data
	tracker.LoadData();   // call function to Load items from file

	int choice = 0;

	// show menu until user chooses to exit
	while (choice != 4) {
		cout << endl;
		cout << "1. Search for an item" << endl;
		cout << "2. Print all item frequencies" << endl;
		cout << "3. Print histogram" << endl;
		cout << "4. Exit program" << endl;
		cout << "Enter choice: ";
		cin >> choice;

		// option 1: search for item
		if (choice == 1) {
			string searchItem;
			cout << "Enteritem name: ";
			cin >> searchItem;

			int freq = tracker.GetItemFrequency(searchItem);
			cout << searchItem << " appears " << freq << " times." << endl;
		}
		// option 2: print all frequencies
		else if (choice == 2) {
			tracker.PrintAllFrequencies();
		}
		// option 3: print histogram
		else if (choice == 3) {
			tracker.PrintHistorgram();
		}
		// option 4: exit program
		else if (choice == 4) {
			cout << "Goodbye!" << endl;
		}
		// anything else is invalid input
		else {
			cout << "Invalid option. Try again." << endl;
		}
	}
	return 0;
}
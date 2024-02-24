

// FileOperations.cpp
#include "FileOperations.h"
#include <iostream>
#include <fstream>
#include "WasteList.h"  // Include the header file for WasteList
#include "WasteStack.h" // Include the header file for WasteStack

using namespace std;

// Implement the functions for file operations
// ...

void saveWasteItemsToFile(WasteList& wasteList, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        WasteItem* current = wasteList.getHead();
        while (current) {
            file << current->name << " " << current->weight << "\n";
            current = current->next;
        }
        file.close();
        cout << "Waste items saved to " << filename << endl;
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}

// Function to load waste items from a file
void loadWasteItemsFromFile(WasteList& wasteList, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string name;
        double weight;
        while (file >> name >> weight) {
            wasteList.addWaste(name, weight);
        }
        file.close();
        cout << "Waste items loaded from " << filename << endl;
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}

// Function to save waste bins to a file
void saveWasteBinsToFile(const WasteStack& wasteStack, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = wasteStack.getTop(); i >= 0; i--) {
            file << wasteStack.getStack()[i].name << " "
                << wasteStack.getStack()[i].capacity << " "
                << wasteStack.getStack()[i].location << " "
                << wasteStack.getStack()[i].type << "\n";
        }
        file.close();
        cout << "Waste bins saved to " << filename << endl;
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}

// Function to load waste bins from a file

void loadWasteBinsFromFile(WasteStack& wasteStack, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string name, location;
        while (file >> name >> location) {
            wasteStack.push(name, location);
        }
        file.close();
        cout << "Waste bins loaded from " << filename << endl;
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}

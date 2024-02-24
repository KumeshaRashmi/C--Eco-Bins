// WasteStack.cpp
#include "WasteStack.h"
#include <iostream>

using namespace std;

WasteStack::WasteStack() : top(-1) {}

void WasteStack::push(const string& name, const string& location) {
    if (top < MAX_STACK_SIZE - 1) {
        WasteBin bin;
        bin.name = name;
        bin.capacity = 20.0; // Fixed capacity of 20 kg
        bin.fillLevel = 0.0; // Initial fill level is zero
        bin.location = location;

        if (location != "Galle" && location != "Matara" && location != "Colombo") {
            cout << "Invalid location. Please choose Galle, Matara, or Colombo." << endl;
            return;
        }

        bin.type = "Generic"; // You can customize the type as needed

        stack[++top] = bin;

        if (isBinFull(top)) {
            cout << "Bin " << name << " at " << location << " is full. Please collect the waste." << endl;
        }
    }
    else {
        cout << "Stack is full. Cannot add more waste bins." << endl;
    }
}

WasteBin WasteStack::pop() {
    if (top >= 0) {
        return stack[top--];
    }
    else {
        cout << "Stack is empty." << endl;
        WasteBin emptyBin; // Return an empty bin to indicate the stack is empty
        return emptyBin;
    }
}

void WasteStack::displayStack() const {
    cout << "Waste Bins:" << endl;
    for (int i = top; i >= 0; i--) {
        cout << "Bin " << stack[i].name << ": Location - " << stack[i].location
            << ", Type - " << stack[i].type << ", Fill Level - " << stack[i].fillLevel << " / " << stack[i].capacity << " kg" << endl;

        if (isBinFull(i)) {
            cout << "Bin " << stack[i].name << " at " << stack[i].location << " is full. Please collect the waste." << endl;
        }
    }
}

void WasteStack::configureBin(const string& name, const string& location) {
    for (int i = top; i >= 0; i--) {
        if (stack[i].name == name) {
            stack[i].location = location;
            cout << "Updated bin location." << endl;

            if (isBinFull(i)) {
                cout << "Bin " << name << " at " << location << " is full. Please collect the waste." << endl;
            }

            return;
        }
    }
    cout << "Bin not found." << endl;
}

int WasteStack::getTop() const {
    return top;
}

const WasteBin* WasteStack::getStack() const {
    return stack;
}

bool WasteStack::isBinFull(int index) const {
    return stack[index].fillLevel >= stack[index].capacity;
}



#pragma once
// WasteStack.h
#ifndef WASTE_STACK_H
#define WASTE_STACK_H

using namespace std;

#include <string>

const int MAX_STACK_SIZE = 5; 
struct WasteBin {
    string name;
    double capacity;
    double fillLevel;
    string location;
    string type;
};

class WasteStack {
private:
    WasteBin stack[MAX_STACK_SIZE];
    int top;

public:
    WasteStack();

    void push(const string& name, const string& location);
    WasteBin pop();
    void displayStack() const;
    void configureBin(const string& name, const string& location);

    int getTop() const;
    const WasteBin* getStack() const;

private:
    bool isBinFull(int index) const;
};

#endif // WASTE_STACK_H





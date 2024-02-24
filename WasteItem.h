#pragma once

#include <string>
using namespace std;

class WasteItem {
public:
    string name;
    double weight;
    WasteItem* next;
};
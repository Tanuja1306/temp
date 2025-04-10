#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;
// Subclasses - Family, Private
class Table {
    public:
        bool isOccupied;
        virtual int bookTable(string name) = 0;
        virtual ~Table() = default;
};
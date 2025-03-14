#pragma once
#include <iostream>
#include "Table.hpp"
using namespace std;

class FamilyTable : public Table {
    public:
        static int tableNumber;
        FamilyTable()
        {
            this->tableNumber++;
        }
        int bookTable(string name)
        {
            cout<<"Booked a family table"<<endl;
            cout<<" Assigned table number: "<<tableNumber<<endl;
            return tableNumber;
        }
};
int FamilyTable::tableNumber = 0;
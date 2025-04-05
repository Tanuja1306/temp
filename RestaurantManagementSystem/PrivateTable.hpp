#pragma once
#include <iostream>
#include "Table.hpp"
using namespace std;

class PrivateTable : public Table {
    public:
        static int tableNumber;
        PrivateTable()
        {
            this->tableNumber++;
        }
        int bookTable(string name)
        {
            cout<<"Booked a private table"<<endl;
            cout<<" Assigned table number: "<<tableNumber<<endl;
            return tableNumber;
        }
};
int PrivateTable::tableNumber = 0;
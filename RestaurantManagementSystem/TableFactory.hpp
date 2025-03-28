#pragma once
#include <iostream>
#include <string>
#include "FamilyTable.hpp"
#include "PrivateTable.hpp"

class TableFactory {
    public:
        int bookTable(string tableType, string name)
        {
            if(tableType == "Family")
            {
                FamilyTable family;
                return family.bookTable(name);
            }
            else 
            {
                PrivateTable privateTable;
                return privateTable.bookTable(name);
            }
        }
};
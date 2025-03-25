#pragma once
#include <iostream>
#include <string>
using namespace std;

class customer {
    public:
        string name;
        long phoneNumber;

        customer(string name, long phoneNumber)
        {
            this->name = name;
            this->phoneNumber = phoneNumber;
        }

        void printCustomerEntryDetails() {
            cout<<"The customer has entered with name: "<<this->name;
            cout<<" and phone number: "<<this->phoneNumber<<endl;
        }
};  
#pragma once
#include <iostream>
#include <string>
#include "Payment.hpp"

class Card : public Payment {
    public:
        void makePayment(string name)
        {
            cout<<"The payment is completed via Card for customer: "<<name<<endl;
        }
};
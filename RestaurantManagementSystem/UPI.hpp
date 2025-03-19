#pragma once
#include <iostream>
#include <string>
#include "Payment.hpp"

class UPI : public Payment {
    public:
        void makePayment(string name)
        {
            cout<<"The payment is completed via UPI for customer: "<<name<<endl;
        }
};
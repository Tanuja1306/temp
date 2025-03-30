#pragma once
#include <iostream>
#include <string>
#include "Payment.hpp"
using namespace std;

class PaymentContext : public Payment {
    public:
        Payment* obj;

        PaymentContext(Payment* obj)
        {
            this->obj = obj;
        }

        void makePayment(string name) 
        {
            this->obj->makePayment(name);
        }
};
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Payment {
    public:

        virtual void makePayment(string name) = 0;
        virtual ~Payment() = default;
};
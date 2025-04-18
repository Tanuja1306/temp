#pragma once
#include <iostream>
#include "PaymentMode.hpp"

class Card : public PaymentMode {
    public:
        void pay() override {
            std::cout<<"The payment is done via card"<<std::endl;
        }
};
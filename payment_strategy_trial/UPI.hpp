#pragma once
#include <iostream>
#include "PaymentMode.hpp"

class UPI : public PaymentMode {
    public:
        void pay() override {
            std::cout<<"The payment is done via UPI"<<std::endl;
        }
};
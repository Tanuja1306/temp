#pragma once
#include <iostream>
#include "PaymentMode.hpp"

class Cash : public PaymentMode {
    public:
        void pay() override {
            std::cout<<"The payment is done via cash"<<std::endl;
        }
};
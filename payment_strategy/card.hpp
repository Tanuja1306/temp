#pragma once
#include "paymentType.hpp"

class card : public paymentType {
    public:
        void payment() override
        {
            std::cout<<"Payment is being done via card"<<std::endl;
        }
};
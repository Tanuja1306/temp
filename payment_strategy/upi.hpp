#pragma once
#include "paymentType.hpp"

class upi : public paymentType {
    public:
        void payment() override
        {
            std::cout<<"Payment is being done via upi"<<std::endl;
        }
};
#pragma once
#include "paymentType.hpp"

class cash : public paymentType {
    public:
        void payment() override
        {
            std::cout<<"Payment is being done via cash"<<std::endl;
        }
};
#pragma once
#include <iostream>
#include <memory>
#include "PaymentMode.hpp"

class PaymentContext {
    public:
        std::unique_ptr<PaymentMode> instance;
    
        void setPaymentInstance(std::unique_ptr<PaymentMode> ptr)
        {   
            this->instance = std::move(ptr);
        }
        
        void pay(std::unique_ptr<PaymentMode> ptr)
        {
            ptr->pay();
        }
};
#pragma once
#include <iostream>

class PaymentMode {
    public:
        virtual ~PaymentMode() = default;
        virtual void pay() = 0;
};
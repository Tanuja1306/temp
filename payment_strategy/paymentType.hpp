#pragma once
#include<iostream>

class paymentType {
    public:
        virtual void payment() = 0;
        virtual ~paymentType() = default;
};
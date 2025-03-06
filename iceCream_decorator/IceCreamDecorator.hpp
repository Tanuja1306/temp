#pragma once
#include "IceCream.hpp"

class IceCreamDecorator : public IceCream {
protected:
    IceCream* instance;

public:
    IceCreamDecorator(IceCream* instance) {
        this->instance = instance;
    }
    virtual ~IceCreamDecorator() {
        delete instance; // free memory
    }
};
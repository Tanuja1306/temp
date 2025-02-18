#pragma once
#include "IceCreamDecorator.hpp"

class CaramelDecorator : public IceCreamDecorator {
public:
    CaramelDecorator(IceCream* instance) : IceCreamDecorator(instance) {}

    string getDescription() override {
        return instance->getDescription() + " + caramel";
    }

    int cost() override {
        return instance->cost() + 15;
    }
};
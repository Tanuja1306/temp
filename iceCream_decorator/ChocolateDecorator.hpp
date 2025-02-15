#pragma once
#include "IceCreamDecorator.hpp"

class ChocolateDecorator : public IceCreamDecorator {
public:
    ChocolateDecorator(IceCream* instance) : IceCreamDecorator(instance) {}

    string getDescription() override {
        return instance->getDescription() + " + chocolate";
    }

    int cost() override {
        return instance->cost() + 20;
    }
};
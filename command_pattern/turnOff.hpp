#pragma once
#include "command.hpp"
#include "tv.hpp"

class turnOff : public command {
    tv& tvInstance;

public:
    turnOff(tv& instance) : tvInstance(instance) {}

    void execute() override {
        tvInstance.turnOff();
    }
};
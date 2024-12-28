#pragma once
#include "Vehicle.hpp"
#include <iostream>

class Bike : public Vehicle {
public:
    void printVehicleType() override {
        std::cout << "This is a bike" << std::endl;
    }
};
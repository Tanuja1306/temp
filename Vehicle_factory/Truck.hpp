#pragma once
#include "Vehicle.hpp"
#include <iostream>

class Truck : public Vehicle {
public:
    void printVehicleType() override {
        std::cout << "This is a truck" << std::endl;
    }
};
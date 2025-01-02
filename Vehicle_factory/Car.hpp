#pragma once
#include <iostream>
#include "Vehicle.hpp"
using namespace std;

class Car : public Vehicle {
    public:
        void printVehicleType() override {
            std::cout << "This is a car" << std::endl;
        }
};
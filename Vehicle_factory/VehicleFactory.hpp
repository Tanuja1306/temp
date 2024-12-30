#pragma once
#include <string>
#include <memory>
#include "Car.hpp"
#include "Bike.hpp"
#include "Truck.hpp"

class VehicleFactory {
public:
    static std::unique_ptr<Vehicle> getInstance(const std::string& type) {
        if (type == "car")
            return std::make_unique<Car>();
        else if (type == "bike")
            return std::make_unique<Bike>();
        else if (type == "truck")
            return std::make_unique<Truck>();
        else
            return nullptr;
    }
};
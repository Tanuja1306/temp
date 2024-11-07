#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "bike.hpp"
#include "truck.hpp"
#include "car.hpp"
#include "vehicle.hpp"

class vehicleFactory {
    public:
        static std::unique_ptr<vehicle> getVehicleInstance(std::string type)
        {
            if(type == "car")
                return std::make_unique<car>();
            else if(type == "bike")
                return std::make_unique<bike>();
            return std::make_unique<truck>();
        }
};

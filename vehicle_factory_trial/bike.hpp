#pragma once
#include "vehicle.hpp"

class bike : public vehicle {
    public:
        void printVehicleType()
        {
            std::cout<<"This is a bike type"<<std::endl;
        }
};
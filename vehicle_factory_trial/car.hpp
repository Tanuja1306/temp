#pragma once
#include "vehicle.hpp"

class car : public vehicle {
    public:
        void printVehicleType()
        {
            std::cout<<"This is a Car type"<<std::endl;
        }
};
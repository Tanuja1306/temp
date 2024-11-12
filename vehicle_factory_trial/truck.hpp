#pragma once
#include "vehicle.hpp"

class truck : public vehicle {
    public:
        void printVehicleType()
        {
            std::cout<<"This is a truck type"<<std::endl;
        }
};
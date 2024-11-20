#pragma once
#include <iostream>

class vehicle {
    public:
        virtual void printVehicleType() = 0;
        virtual ~vehicle() = default;
};

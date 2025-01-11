#pragma once

class Vehicle {
    public:
        virtual void printVehicleType() = 0;
        virtual ~Vehicle() = default;
};
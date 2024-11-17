#include <iostream>
#include "vehicleFactory.hpp"

using namespace std;

int main()
{
    auto car = vehicleFactory::getVehicleInstance("car");
    auto bike = vehicleFactory::getVehicleInstance("bike");
    auto truck = vehicleFactory::getVehicleInstance("truck");

    car->printVehicleType();
    bike->printVehicleType();
    truck->printVehicleType();
}
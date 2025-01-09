#include "VehicleFactory.hpp"

int main() {
    std::unique_ptr<Vehicle> car = VehicleFactory::getInstance("car");
    std::unique_ptr<Vehicle> bike = VehicleFactory::getInstance("bike");
    std::unique_ptr<Vehicle> truck = VehicleFactory::getInstance("truck");

    if (car) car->printVehicleType();
    if (bike) bike->printVehicleType();
    if (truck) truck->printVehicleType();

    return 0;
}
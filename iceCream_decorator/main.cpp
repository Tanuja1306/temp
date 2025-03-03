#include <iostream>
#include "VanillaIceCream.hpp"
#include "ChocolateDecorator.hpp"
#include "CaramelDecorator.hpp"

int main() {
    IceCream* base = new VanillaIceCream();
    IceCream* withChocolate = new ChocolateDecorator(base);
    IceCream* withCaramel = new CaramelDecorator(withChocolate);

    std::cout << "Description: " << withCaramel->getDescription() << std::endl;
    std::cout << "Cost: " << withCaramel->cost() << std::endl;

    delete withCaramel; // This will delete entire chain
    return 0;
}
#pragma once

#include <string>
#include <iostream>
using namespace std;

class IceCream {
    public:
        virtual string getDescription() = 0;
        virtual int cost() = 0;
        virtual ~IceCream() {}
};
#pragma once
#include <iostream>
#include <string>
#include "IceCream.hpp"
using namespace std;

class VanillaIceCream : public IceCream {
    public:
        string getDescription() override {
            return "This is a vanilla icecream";
        }

        int cost() override {
            return 100;
        }
};
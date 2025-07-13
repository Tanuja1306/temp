#pragma once
#include <iostream>
using namespace std;

class tv {
public:
    bool state = false;

    void turnOn() {
        state = true;
        cout << "The TV is turned ON" << endl;
    }

    void turnOff() {
        state = false;
        cout << "The TV is turned OFF" << endl;
    }
};
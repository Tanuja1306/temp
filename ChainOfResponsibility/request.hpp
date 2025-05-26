#pragma once
#include <iostream>
#include <string>
using namespace std;

class request {
    public:
        string priority;
        request(string priority) {
            this->priority = priority;
        }
        string getPriority()
        {
            return priority;
        }
};
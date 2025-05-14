#pragma once
#include <iostream>
#include "request.hpp"

using namespace std;

class handler {
    public:
        virtual void handleRequest(request r) = 0;
        virtual void setNextHandler(handler* h) = 0;
};
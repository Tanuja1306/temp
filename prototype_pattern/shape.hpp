#pragma once
#include <iostream>

class shape {
    public:
        virtual void draw() = 0;
        virtual shape* clone() = 0;
        virtual ~shape() = default;
};
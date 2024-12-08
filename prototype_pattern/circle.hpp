#pragma once
#include <string>
#include <iostream>
#include "shape.hpp"
using namespace std;

class circle : public shape{
    public:
        std::string color;

        circle(const string& color)
        {
            this->color = color;
        }

        void draw() override {
            cout<<"The circle is drawn of color "<<color<<endl;
        }

        shape* clone() override
        {
            return new circle(color);
        }
};
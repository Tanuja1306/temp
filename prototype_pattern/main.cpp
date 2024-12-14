#include <iostream>
#include "circle.hpp"
#include "shape.hpp"
using namespace std;

int main()
{
    shape* redCircle = new circle("red");
    redCircle->draw();
    shape* clonedCircle = redCircle->clone();
    clonedCircle->draw();
}
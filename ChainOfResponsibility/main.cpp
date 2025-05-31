#include <iostream>
#include "request.hpp"
#include "levelA.hpp"
#include "levelB.hpp"
#include "levelC.hpp"
#include "handler.hpp"

using namespace std;

int main()
{
    handler* levelAinstance = new levelA();
    handler* levelBinstance = new levelB();
    handler* levelCinstance = new levelC();

    levelAinstance->setNextHandler(levelBinstance);
    levelBinstance->setNextHandler(levelCinstance);

    levelAinstance->handleRequest(request("Basic"));
    levelAinstance->handleRequest(request("Medium"));
    levelAinstance->handleRequest(request("High"));
}
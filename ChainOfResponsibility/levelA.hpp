#pragma once
#include <iostream>
#include "handler.hpp"

class levelA : public handler {
    
    handler* nextInstance;

    public:

        void handleRequest(request r) override
        {
            if(r.getPriority() == "Basic")
            {
                cout<<"The request is handled as it was BASIC by level A"<<endl;
            }
            else
            {
                nextInstance->handleRequest(r);
            }
        }
        void setNextHandler(handler* h) override
        {
            this->nextInstance = h;
        }
};
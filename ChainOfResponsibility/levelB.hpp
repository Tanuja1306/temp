#pragma once
#include <iostream>
#include "handler.hpp"

class levelB : public handler {
    
    handler* nextInstance;

    public:

        void handleRequest(request r) override
        {
            if(r.getPriority() == "Medium")
            {
                cout<<"The request is handled as it was Medium by level B"<<endl;
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
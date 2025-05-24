#pragma once
#include <iostream>
#include "handler.hpp"

class levelC : public handler {
    
    public:
        void handleRequest(request r) override
        {
            if(r.getPriority() == "High")
            {
                cout<<"The request is handled as it was HIGH by level C"<<endl;
            }
            else
            {
                cout<<"Customer support cannot handle the request"<<endl;
            }
        }
        void setNextHandler(handler* h) override {}
};
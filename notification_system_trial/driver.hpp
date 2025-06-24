#pragma once
#include "observer.hpp"
#include <iostream>

using namespace std;

class driver : public observer{
    public:

        int driver_id;
        int phone_number;
        driver(int driver_id, int phone_number)
        {
            this->driver_id = driver_id;
            this->phone_number = phone_number;
        }

        void update() {
            cout<<"The observer is being updated"<<endl;
            cout<<"     Driver Id:"<<driver_id;
            cout<<"   Phone Number:"<<phone_number<<endl;
        }
};
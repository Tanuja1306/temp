#pragma once
#include "observer.hpp"
#include <iostream>
#include <vector>

class notifier{
    public:
        std::vector<observer*> observerList;

        void addObserver(observer* obj)
        {
            observerList.push_back(obj);
        }

        void notifyAllUsers()
        {
            for(auto o : observerList)
            {
                o->update();
            }
        }
};
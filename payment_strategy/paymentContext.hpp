#pragma once
#include <memory>
#include "paymentType.hpp"

class PaymentContext {
private:
    std::unique_ptr<paymentType> strategy;

public:
    void setPaymentMethod(std::unique_ptr<paymentType> method) {
        strategy = std::move(method);
    }

    void makePayment() {
        if (strategy)
            strategy->payment();
        else
            std::cout << "No payment method selected!" << std::endl;
    }
};
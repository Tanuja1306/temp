#include <iostream>
#include <memory>
using namespace std;

#include "UPI.hpp"
#include "Cash.hpp"
#include "Card.hpp"
#include "PaymentContext.hpp"

int main()
{
    PaymentContext payment;
    UPI obj;
    payment.setPaymentInstance(std::make_unique<UPI>(obj));
    payment.pay(std::make_unique<UPI>(obj));

    Cash obj1;
    payment.setPaymentInstance(std::make_unique<Cash>(obj1));
    payment.pay(std::make_unique<Cash>(obj1));
}
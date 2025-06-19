#include <iostream>
#include "paymentContext.hpp"
#include "card.hpp"
#include "cash.hpp"
#include "upi.hpp"

int main() {
    PaymentContext payment;

    payment.setPaymentMethod(std::make_unique<upi>());
    payment.makePayment();

    payment.setPaymentMethod(std::make_unique<cash>());
    payment.makePayment();

    payment.setPaymentMethod(std::make_unique<card>());
    payment.makePayment();

    return 0;
}
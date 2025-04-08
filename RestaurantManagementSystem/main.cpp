#include <iostream>
#include "TableFactory.hpp"
#include "FamilyTable.hpp"
#include "customer.hpp"
#include <unordered_map>
#include "Payment.hpp"
#include "PaymentContext.hpp"
#include "UPI.hpp"
#include "Card.hpp"
int main()
{
    std::unordered_map<string, int> CustomerToTableMap;
    TableFactory tableFactory;

    // First customer
    customer c1("Tanuja", 9245678000);
    c1.printCustomerEntryDetails();
    int t1 = tableFactory.bookTable("Family", c1.name);
    CustomerToTableMap[c1.name] = t1;
    cout<<endl;
    // Second customer
    customer c2("Neha", 923678070);
    c2.printCustomerEntryDetails();
    int t2 = tableFactory.bookTable("Family", c2.name);
    CustomerToTableMap[c2.name] = t1;
    cout<<endl;
    // Third customer
    customer c3("Himanshi", 9245673410);
    c3.printCustomerEntryDetails();
    int t3 = tableFactory.bookTable("Private", c3.name);
    CustomerToTableMap[c3.name] = t1;
    cout<<endl;

    PaymentContext(new Card()).makePayment(c1.name);

    PaymentContext(new UPI()).makePayment(c3.name);
}
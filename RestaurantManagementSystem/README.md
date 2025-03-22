# Restaurant Management System

## Requirement Analysis
	1.	Table Booking – Customers can book tables via app or at the restaurant.
	2.	Table Categories – Supports private, party, and regular seating.
	3.	Inventory Management – Tracks stock of raw/cooked food items.
	4.	Stock Monitoring – Triggers alerts when stock levels fall below threshold.
	5.	Dynamic Menu – Menu auto-updates based on current stock.
	6.	Order Placement – Orders can be placed via mobile app or manually.
	7.	Ticket Issuance – Generates tracking ticket for each order.
	8.	Takeaway Support – Customers can place takeout orders via app.
	9.	Delivery Integration – Supports in-house and third-party delivery (e.g., Swiggy/Zomato).
	10.	Payment System – Customers pay before leaving.
	11.	Bill Calculation – Computes bill with taxes and customization charges.
	12.	Notifications – Alerts customer when order is ready or payment succeeds.
	13.	Staff Management – Maintains staff availability and assignments.
	14.	Sales Analytics – Tracks restaurant performance by region, time, etc.
    15. Menu sections - Beverage, main course, starters, dessert

## Key Metrics
    •	Scalability – Easily extend table types, menu categories, or payment methods.
	•	Fault Tolerance – Graceful fallbacks in case of payment/server failures.
	•	Data Consistency – Ensures accurate mapping of orders, payments, and inventory.
	•	Extensibility – Modular design allows for new integrations with minimal changes.

## Design Patterns Used
1. Singleton
Restaurant management system, InventoryManager, staff management (Pantry, cooking, reception, cleaning, waiter, gaurd) have one shared instance.
2. Factory
Creates appropriate Table (e.g., PartyTable, PrivateTable) based on request. Dish creation via factory pattern
3. Strategy
Runtime selection of payment methods (Cash, UPI, Card) via PaymentContext.
4. Decorator
Add-ons (e.g., ice cream toppings, pizza customizations) wrapped around base dishes.
5. Prototype
Clone frequently ordered dishes with customizations to reduce creation overhead.
6. Observer
NotificationService pushes updates to multiple users/staff upon order status changes.
7. Adapter
Integrates offline and online booking interfaces to a unified BookingService.
8. Chain of Responsibility
Discount strategy (Regular, new, loyal, elite customers).

## Classes
1. RestaurantManager (Singleton)
	•	Data Members
	•	    vector<Table*> tables
	•	    Menu* menu
	•	    InventoryManager* inventoryManager
	•	    StaffManager* staffManager
	•	    OrderManager* orderManager
	•	    NotificationService* notifier
	•	Methods
	•	    static RestaurantManager* getInstance()
	•	    void initializeRestaurant()
	•	    void handleBookingRequest(...)
	•	    void handleOrder(...)

2. Table (Abstract Base Class)
	•	Data Members
	•	    int tableId
	•	    int capacity
	•	    bool isAvailable
	•	Methods
	•	    virtual string getCategory()
	•	    void reserveTable()
	•	    void releaseTable()

Subclasses: RegularTable, PrivateTable, PartyTable

3. MenuItem
	•	Data Members
	•	    string name
	•	    float basePrice
	•	Methods
	•	    virtual float getPrice()
	•	    virtual string getDescription()

Decorators: CheeseDecorator, ExtraToppingDecorator, etc.

4. InventoryManager (Singleton)
	•	Data Members
	•	    unordered_map<string, int> itemStock
	•	    int lowStockThreshold
	•	Methods
	•	    void updateStock(string item, int qty)
	•	    bool isAvailable(string item)
	•	    void notifyLowStock()

5. Order
	•	Data Members
	•	    int orderId
	•	    vector<MenuItem*> items
	•	    OrderStatus status
	•	Methods
	•	    void addItem(MenuItem*)
	•	    float calculateTotal()
	•	    void updateStatus(OrderStatus)

6. OrderManager
	•	Data Members
	•	    unordered_map<int, Order*> orderMap
	•	Methods
	•	    Order* createOrder()
	•	    void updateOrderStatus(int orderId, OrderStatus)
	•	    Order* getOrder(int orderId)

7. PaymentContext
	•	Data Members
	•	    PaymentStrategy* paymentMethod
	•	Methods
	•	    void setPaymentMethod(PaymentStrategy*)
	•	    void pay(float amount)

Implementations: CardPayment, CashPayment, UPIPayment

8. NotificationService (Observer Pattern)
	•	Data Members
	•	    vector<Observer*> observers
	•	Methods
	•	    void addObserver(Observer*)
	•	    void removeObserver(Observer*)
	•	    void notifyAll(string message)

9. Staff
	•	Data Members
	•	    int staffId
	•	    string name
	•	    Role role
	•	    bool isAvailable
	•	Methods
	•	    void assignToTask(string)
	•	    void markAvailable()

10. StaffManager
	•	Data Members
	•	    vector<Staff*> staffList
	•	Methods
	•	    Staff* findAvailableStaff(Role)
	•	    void updateAvailability(...)

11. Analytics
	•	Data Members
	•	    vector<Order*> completedOrders
	•	    map<string, float> revenueByDate
	•	Methods
	•	    void generateDailyReport()
	•	    void calculatePeakHours()

## System Flow – Restaurant Management System

1. Table Booking
	•	Customer (online/offline) requests table.
	•	RestaurantManager handles the booking.
	•	Uses Factory Pattern to create a table (PrivateTable, PartyTable, RegularTable).
	•	Table is reserved and mapped to customer.

2. Menu Display & Inventory Check
	•	Customer views menu.
	•	InventoryManager (a Singleton) checks ingredient availability.
	•	Unavailable items are marked as out of stock.
	•	If stock is low, Observer Pattern notifies kitchen/staff.

3. Order Placement
	•	Customer selects items and places the order.
	•	OrderManager creates an Order.
	•	Items with customizations (e.g., toppings) use Decorator Pattern.
	•	Order ticket is generated.

4. Cooking Flow
	•	KitchenManager receives order.
	•	Uses Chain of Responsibility Pattern to assign dish to available cook based on skill and load.
	•	Cooking completed and status updated.

5. Order Ready Notification
	•	Once ready, Observer Pattern notifies the customer.

6. Payment Process
	•	Before leaving, customer makes payment.
	•	PaymentContext uses Strategy Pattern to process payment (Cash, UPI, Card).

7. Takeaway/Delivery

	•	If takeaway, ticket is marked for pickup.
	•	If delivery, integrated via Adapter Pattern to support third-party apps like Swiggy/Zomato.

8. Analytics & Staff Management
	•	Sales, orders, and table usage tracked by AnalyticsModule.
	•	StaffManager tracks availability, replacements, and hiring.

## Future Scope
1. AI-based Recommendation System:
Suggest dishes to customers based on past orders, time of day, or trending items.
2. Dynamic Pricing Module:
Integrate surge-based pricing or discounts based on demand, time slots, or customer loyalty.

## Interview Perspective

- Restaurant management system (Singleton)
1. Table Booking - FACTORY design pattern
2. Menu Display - FACTORY pattern
3. Order place - Concrete class
4. Order dispersal - Concrete
5. Payment - Strategy
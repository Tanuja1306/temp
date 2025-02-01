# Parking Lot

## Requirement Analysis:

1. The parking lot supports **multiple parking slots**, organized into levels for efficient allocation.
2. It can accommodate **various vehicle types** (e.g., bike, car, truck).
3. The parking lot has **multiple entry and exit gates**, each with awareness of its surrounding slot locations.
4. Vehicle are assigned the **nearest available parking slot** based on the entry point to minimize walking distance.
5. The system **charges parking fees** at exit, calculated based on the type of vehicle and duration of stay.
6. Upon entry and exit, the system sends **notifications** to confirm parking details (slot number, fee, etc.).

## Key Metrics

- **Scalable**: Design supports multi-level parking and future capacity expansion.
- **Extensible**: Easily accommodates new vehicle types, gates, or payment providers.
- **Secure**: Notification system integrated for entry/exit tracking.

## Classes (Bottom up approach)

1. ParkingLot
    - Data Members
        Map<Gate, PriorityQueue<ParkingSlot>> per gate management
        Map<VehicleId, ParkingSlot> for vehicle slot mapping
    - Method
        assignSlot(Vehicle, Gate)
        releaseVehicle(Gate)
        getAvailableSlotCount()

2. ParkingSlot
    - Data members
        bool isCarParked
        int slotId
        int vehicleId
        VehicleType supportedType
        isEvChargingSupported
        Level level (for multi level parking)
    - Methods
        park()
        unpark()
        detachChargerCable()
    
3. Vehicle
    - Data members
        string VehicleId
        vehicle_type
    - Method
        getParkingDuration()

5. Ticket
    - Data members
        entryTime
        phoneNumber
        slotId
        entryGate
        level
        vehicle
    - Method
        getTicket(int)
        notifyDriver()

4. Gates
    - EntryGate
        Method
            getNearestSlot()
    - ExitGate
        Method
            PaymentManager.calculateFare()
            notify()

5. PaymentMethod
    - Cash
    - Card
    - UPI

6. Notification Management System
    - Data Member
        List of observers (vehicleID)
    Method
        addObserver(User)
        notify(vehicleId, message)
        notifyAllUser(string emergency)

## SOLID Principles in Parking Lot Design

- **Single Responsibility**  
  → `ParkingSlot` manages slot availability, `PaymentManager` handles transaction logic, and `Vehicle` stores vehicle-specific info.
- **Open/Closed**  
  → Adding a new `PaymentMethod` (e.g., Wallet) or `VehicleType` requires no code changes in existing logic due to use of interfaces and Strategy Pattern.
- **Liskov Substitution**  
  → `Card`, `Cash`, and `UPI` are interchangeable via the `PaymentMethod` interface inside `PaymentManager`.
- **Interface Segregation**  
  → Instead of one large Gate interface, I use separate `EntryGate` and `ExitGate` classes for specific gate responsibilities.
- **Dependency Inversion**  
  → `ParkingLot` and `ExitGate` interact with `PaymentMethod` via an abstract interface, not concrete classes, improving flexibility and testability.

## Design patterns

- Parking lot (singleton design pattern) - We need only single global instance/object of this top level class
- Payment management system (strategy design pattern) - We can accomodate different types of payment methods
- Fare calculation (strategy design pattern)
- Notification system (Observer design pattern) - During state change (entry/release of slot), observers(vehicle) will be notified
- Vehicle type (factory design pattern) - We want to support different types of vehicles

## System flow

`Vehicle Entry Flow`:

Vehicle 
  → EntryGate 
    -> ticket.createTicket(vehicleId, vehicleType, phoneNumber)
    → ParkingLot.assignSlot(vehicle, gate)
      → ParkingSlot.park()
      → NotificationSystem.notify(vehicle.phone, "Parked at L2-S14")

`Vehicle Exit Flow`:

Vehicle 
  → ExitGate 
    → ParkingLot.releaseVehicle(vehicleId)
      → ParkingSlot.unpark()
      -> calculateFare(entryTime, exitTime)
      → PaymentSystem
      → NotificationSystem.notify(vehicle.phone, "Charged ₹80. Thank you!")

## Move to the skeleton (Implementation of core classes and a minimal main() or Client code to simulate flow)

## Test Cases/Scenarios: Full lot, duplicate vehicle, payment failure.
## How to scale: multi-level, real-time slot dashboard, horizontal scaling(multi level, slot count increase), EV vehicle support.
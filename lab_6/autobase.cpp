#include "AutoBase.h"
#include <iostream>

// Реализация класса Auto
Auto::Auto(const std::string& model) : model(model) {}

void Auto::displayCarInfo() const {
    std::cout << "Model: " << model << std::endl;
}

// Реализация класса Car
Car::Car(const std::string& model) : Auto(model) {}

void Car::displayCarInfo() const {
    std::cout << "Car - ";
    Auto::displayCarInfo();
}

// Реализация класса Employee
Employee::Employee(const std::string& name) : name(name) {}

void Employee::displayDriverInfo() const {
    std::cout << "Name: " << name << std::endl;
}

std::string Employee::getName() const { // Реализация геттера для имени
    return name;
}

// Реализация класса Driver
Driver::Driver(const std::string& name) : Employee(name), isSuspended(false) {}

void Driver::markTripCompletion(Trip& trip, Car& car) {
    std::cout << "Driver " << name << " completed trip to ";
    trip.displayTripInfo();
}

void Driver::requestRepair(Car& car) {
    std::cout << "Driver " << name << " requests repair for car: ";
    car.displayCarInfo();
}

void Driver::displayDriverInfo() const {
    std::cout << "Driver - ";
    Employee::displayDriverInfo();
}

// Реализация класса Dispatcher
Dispatcher::Dispatcher(const std::string& name) : Employee(name) {}

void Dispatcher::displayDispatcherInfo() const {
    std::cout << "Dispatcher Name: " << name << std::endl;
}

void Dispatcher::addCar(Car* car) {
    cars.push_back(car);
}

void Dispatcher::addDriver(Driver* driver) {
    drivers.push_back(driver);
}

void Dispatcher::addTrip(Trip* trip) {
    trips.push_back(trip);
}

void Dispatcher::addRequest(const std::string& request) {
    requests.push_back(request);
}

void Dispatcher::assignTrip(Trip* trip, Driver* driver, Car* car) {
    std::cout << "Dispatcher " << name << " assigned trip to driver " << driver->getName()
              << " with car: ";
    car->displayCarInfo();
}

void Dispatcher::suspendDriver(Driver* driver) {
    std::cout << "Dispatcher " << name << " suspended driver " << driver->getName() << std::endl;
}

const std::vector<Car*>& Dispatcher::getCars() const {
    return cars;
}

const std::vector<Driver*>& Dispatcher::getDrivers() const {
    return drivers;
}

const std::vector<Trip*>& Dispatcher::getTrips() const {
    return trips;
}

// Реализация класса Trip
Trip::Trip(const std::string& destination) : destination(destination), isCompleted(false) {}

void Trip::displayTripInfo() const {
    std::cout << "Destination: " << destination << std::endl;
}

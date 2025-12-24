#ifndef AUTOBASE_H
#define AUTOBASE_H

#include <string>
#include <vector>

// Базовый класс для всех транспортных средств
class Auto {
public:
    Auto(const std::string& model);
    virtual ~Auto() {}
    virtual void displayCarInfo() const;
protected:
    std::string model;
};

// Класс для автомобилей
class Car : public Auto {
public:
    Car(const std::string& model);
    void displayCarInfo() const override;
};

// Базовый класс для всех сотрудников
class Employee {
public:
    Employee(const std::string& name);
    virtual ~Employee() {}
    virtual void displayDriverInfo() const;
    std::string getName() const; // Добавляем геттер для имени
protected:
    std::string name;
};

// Класс для водителей
class Driver : public Employee {
public:
    Driver(const std::string& name);
    void markTripCompletion(class Trip& trip, Car& car);
    void requestRepair(Car& car);
    void displayDriverInfo() const override;
private:
    bool isSuspended;
};

// Класс для диспетчеров
class Dispatcher : public Employee {
public:
    Dispatcher(const std::string& name);
    void displayDispatcherInfo() const;
    void addCar(Car* car);
    void addDriver(Driver* driver);
    void addTrip(class Trip* trip);
    void addRequest(const std::string& request);
    void assignTrip(class Trip* trip, Driver* driver, Car* car);
    void suspendDriver(Driver* driver);
    const std::vector<Car*>& getCars() const;
    const std::vector<Driver*>& getDrivers() const;
    const std::vector<Trip*>& getTrips() const;
private:
    std::vector<Car*> cars;
    std::vector<Driver*> drivers;
    std::vector<class Trip*> trips;
    std::vector<std::string> requests;
};

// Класс для рейсов
class Trip {
public:
    Trip(const std::string& destination);
    void displayTripInfo() const;
private:
    std::string destination;
    bool isCompleted;
};

#endif

//Реализовать иерархию классов "Транспортное средство". 
//Базовый класс - транспорт, производные - самолёт, судно, грузовик, велосипед и легковой автомобиль.
//Метод вывода и метод расхода топлива реализовать как virtual.
// Реализовать меню для создания объектов.Объекты создаются через единственный указатель на базовый класс.transport

#include <iostream>
#include <string>
using namespace std;

class Transport {
protected:
    string model;
    double consumption;

public:
    Transport(const string& m, double c) : model(m), consumption(c){}

    virtual void Print() const {
        cout << "Transport model: " << model << endl;
    }
    virtual void fuelConsumption() const {
        cout << "Fuel consumption: " << consumption << endl;
    }
};

class Airplane : public Transport {
    double speed;
public:
    Airplane(const string& m, double c, double s) : Transport(m, c), speed(s) {}

    void Print() const override {
        cout << "\nAirplane: \n";
        Transport::Print();
        cout << "Speed: " << speed << endl;
    }

    void fuelConsumption() const override {
        Transport::fuelConsumption();
    }
};

class Ship : public Transport {
    double speed;
public:
    Ship(const string& m, double c, double s) : Transport(m, c), speed(s) {}

    void Print() const override {
        cout << "\nShip: \n";
        Transport::Print();
        cout << "Speed: " << speed << endl;
    }

    void fuelConsumption() const override {
        Transport::fuelConsumption();
    }
};

class Truck : public Transport {
    int numberOfWheels;
public:
    Truck(const string& m, double c, int wheels) : Transport(m, c), numberOfWheels(wheels) {}

    void Print() const override {
        cout << "\nTruck: " << endl;
        Transport::Print();
        cout << "Number of wheels: " << numberOfWheels << endl;
    }

    void fuelConsumption() const override {
        Transport::fuelConsumption();
    }
};

class Bicycle : public Transport {
    int numberOfWheels;
public:
    Bicycle(const string& m, double c, int wheels) : Transport(m, c), numberOfWheels(wheels) {}

    void Print() const override {
        cout << "\nBicycle:\n";
        Transport::Print();
        cout << "Number of wheels: " << numberOfWheels << endl;
    }

    void fuelConsumption() const override {
        Transport::fuelConsumption();
        cout << "Bicycles don't use fuel" << endl;
    }
};

class Car : public Transport {
    double speed;
    int numberOfWheels;
public:
    Car(const string& m, double c, int wheels, double s) : Transport(m, c), numberOfWheels(wheels), speed(s) {}

    void Print() const override {
        cout << "\nCar:\n";
        Transport::Print();
        cout << "Speed: " << speed << endl;
        cout << "Number of wheels: " << numberOfWheels << endl;
    }

    void fuelConsumption() const override {
        Transport::fuelConsumption();
    }
};


void Choice(Transport*& transports) {

    Airplane airplane("Boeing", 5700, 850);
    Ship ship("Titanic", 610, 42);
    Truck truck("Volvo", 16, 4);
    Bicycle bicycle("Mountain Bike", 5, 2);
    Car car("Toyota Camry", 8.3, 4, 180);

    cout << "Choose a transport type:" << endl;
    cout << "1. Airplane" << endl;
    cout << "2. Ship" << endl;
    cout << "3. Truck" << endl;
    cout << "4. Bicycle" << endl;
    cout << "5. Car" << endl;

    int choice;
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        transports = &airplane;
        transports->Print();
        transports->fuelConsumption();
        break;
    case 2:
        transports = &ship;
        transports->Print();
        transports->fuelConsumption();
        break;
    case 3:
        transports = &truck;
        transports->Print();
        transports->fuelConsumption();
        break;
    case 4:
        transports = &bicycle;
        transports->Print();
        transports->fuelConsumption();
        break;
    case 5:
        transports = &car;
        transports->Print();
        transports->fuelConsumption();
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
}


int main() {
    Transport* transports;
    for (int i = 0; i < 5; i++)
    {
         Choice(transports);
    }
    return 0;
}



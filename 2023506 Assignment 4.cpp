#include <iostream>
#include <string>
using namespace std;

class Engine {
private:
    int cylinders;
    int horsepower;

public:
    Engine(int c, int h) : cylinders(c), horsepower(h) {}


    int getCylinders() const {
        return cylinders;
    }

    int getHorsepower() const {
        return horsepower;
    }
};

class Car {
private:
    string make;
    string model;
    Engine e;

public:
    Car(string m, string mo, Engine eng) : make(m), model(mo), e(eng) {}

    void PrintInfo() const {
        cout << "Make is: " << make << endl << "Model is: " << model << endl
             << "Horsepower: " << e.getHorsepower() << " HP" << endl
             << "No. of Cylinders: " << e.getCylinders() << endl;
    }
};

int main() {
    int x;
    cout << "Welcome to the dealership!\n"
         << "Please select the car you want details on!\n";
    cout << "1. Honda\n2. Ferrari\n3. Lamborghini\n";
    cin >> x;

    switch (x) {
    case 1: {
        Engine hondaEngine(4, 200);
        Car honda("Honda", "Civic", hondaEngine);
        honda.PrintInfo();
        break;
    }

    case 2: {
        Engine ferrariEngine(8, 600); 
        Car ferrari("Ferrari", "458 Italia", ferrariEngine);
        ferrari.PrintInfo();
        break;
    }

    case 3: {
        Engine lamboEngine(12, 700);
        Car lambo("Lamborghini", "Aventador", lamboEngine);
        lambo.PrintInfo();
        break;
    }

    default:
        cout << "Invalid selection!";
    }

    return 0;
}



#include <iostream>

class Car {
private:
    float fuel;
    float fuel_cons_coef;
public:
    float speed;

    Car() : fuel(300), speed(0), fuel_cons_coef(1.0) {
    }

    Car( float new_f, float new_s ) : fuel(new_f), speed(new_s) {
    }

    void SpeedUp( float accel ) {
        if (fuel >= 0) {
            speed += accel;
            fuel -= 2.0 / 5 * accel * fuel_cons_coef;
            fuel_cons_coef += 0.1;
        }
    }

    void SetFuel( float new_value ) {
        fuel = new_value;
    }

    float GetFuel( void ) {
        return this->fuel;
    }

    void SetFuelCoef( float new_value ) {
        fuel_cons_coef = new_value;
    }

    float GetFuelCoef() {
        return this->fuel_cons_coef;
    }
};

class truck : public Car {
public:
    truck() {
        SetFuelCoef(2.5);
    }

    void Ride() {
        bool ride = true;
        while(ride) {
            if (GetFuel() == 0) {
                ride = false;
                std::cout << "Truck is out of fuel:(\n";
            }

            std::cout << "\nTruck fuel: " << GetFuel();

            if (rand() % 4 == 0) {
                SpeedUp(10);
            }

            SetFuel(GetFuel() - GetFuelCoef() * speed / 2);
        }
    }
};

class motorcycle : public Car {
public:
    motorcycle() {
        SetFuelCoef(0.8);
    }

    bool RideOnOneWheel() {
        return rand() & 1 == 0;
    }

    void Ride() {
        bool ride = true, wheelee = false;
        while(ride) {
            if (GetFuel() == 0) {
                ride = false;
                std::cout << "Motorcycle is out of fuel:(\n";
            }

            if (rand() % 2 == 0) {
                SpeedUp(10);
            }

            std::cout << "\nMoto fuel: " << GetFuel();

            if (RideOnOneWheel() && !wheelee) {
                SetFuelCoef(GetFuelCoef() + 0.2);
                wheelee = true;
            } else if (wheelee) {
                wheelee = false;
                SetFuelCoef(GetFuelCoef() - 0.2);
            }

            SetFuel(GetFuel() - GetFuelCoef() * speed / 3);
        }
    }
};
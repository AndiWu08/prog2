#include "Car.h"

int main() {
    Car car1;
    car1.displayInfo();
    car1.setBrand(Car::BrandType::BMW);
    car1.setModel("M3");
    car1.setKm(15000.4);
    car1.setYear(2010);
    car1.displayInfo();

    Car car2(Car::BrandType::SUZUKI, "Swift", 2012, 85000.8);
    car2.displayInfo();
}
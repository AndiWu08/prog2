#pragma once

#include <string>
#include <cstdint>

class Car {
    public:
        enum class BrandType {
            UNKNOWN,
            TOYOTA,
            FORD,
            VOLKSWAGEN,
            AUDI,
            BMW,
            SUZUKI
        };
    private:
        BrandType m_brand;
        std::string m_model;
        uint16_t m_year;
        double m_km;
    
    public:
        //Standardkonstruktor
        Car();

        // Konstruktor mit Werten
        Car(const BrandType brand, const std::string model, uint16_t year, double km);

        /// Destruktor
        ~Car();

        // Getter Methoden
        BrandType getBrand() const;
        std::string getModel() const;
        uint16_t getYear() const;
        double getKm() const;

        // Setter Methoden
        void setBrand(const BrandType brand);
        void setModel(const std::string &model);
        void setYear(uint16_t year);
        void setKm(double km);

        // drive the car
        void drive(double km);

        // display car info
        void displayInfo();
};
#include "Car.h"
#include <iostream>

Car::Car() : 
    m_brand(BrandType::UNKNOWN),
    m_model("UNKNOWN"),
    m_year(2000),
    m_km(0.0)
    {
        std::cout << "Standardkonstruktor wurde aufgerufen" << std::endl;
    }

Car::Car(const BrandType brand, const std::string model, uint16_t year, double km)
    : m_brand(brand), m_model (model), m_year(year), m_km(km)
    {
        std::cout << "Konstruktor wurde aufgerufen Brand: " << static_cast<int>(m_brand) << " model: " << m_model << " year: " << m_year << " km: " << m_km << std::endl;
    }

Car::~Car() 
{
    std::cout << "Auto wurde zerstört" << std::endl;
}

// Getter Methoden
Car::BrandType Car::getBrand() const
{
    return m_brand;
}

std::string Car::getModel() const
{
    return m_model;
}

uint16_t Car::getYear() const
{
    return m_year;
}

double Car::getKm() const
{
    return m_km;
}

// Setter Methoden
void Car::setBrand(const Car::BrandType brand) {
    m_brand = brand;
}

void Car::setModel(const std::string &model) {
    m_model = model;
}

void Car::setYear(uint16_t year) {
    if ((year >= 1886) && (year < 2026))
    {
        m_year = year;
    }
    else
    {
        std::cout << "Bitte Baujahr überprüfen" << std::endl;
    } 
}

void Car::setKm(double km) {
    if (km >= 0)
    {
        m_km = km;
    }
    else
    {
        std::cout << "Kilometerstand kann nicht negativ sein" << std::endl;
    }
    
}

void Car::drive(double km) {
    if (km >= 0)
    {
        m_km += km;
    }
    else
    {
        std::cout << "Kilometerstand kann nicht zurückgedreht werden" << std::endl;
    }
}

void Car::displayInfo() {
    std::cout << "Informationen zum Auto" << std::endl;
    std::cout << "Marke: " << static_cast<int>(m_brand) << std::endl;
    std::cout << "Model: " << m_model << std::endl;
    std::cout << "Baujahr: " << m_year << std::endl;
    std::cout << "Kilometerstand: " << m_km << std::endl;
}


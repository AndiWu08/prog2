#pragma once
#include <string>

class Address {
    private:
        std::string m_street;
        std::string m_city;
        std::string m_country;

    public: 
        // Konstruktor
        Address(const std::string& street, 
            const std::string& city, 
            const std::string& country) 
            : m_street{street}
             , m_city{city}
             , m_country{country} {}

        // Getter Methoden
        const std::string& getStreet() const    { return m_street; }
        const std::string& getCity() const      { return m_city; }   
        const std::string& getCountry() const   { return m_country; }
};
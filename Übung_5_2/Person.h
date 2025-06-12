#pragma once
#include <string>
#include "Address.h"

class Person {
    private:
        std::string m_firstName;
        std::string m_lastName;
        Address m_address;

    public:
        // Constructor with parameters for Person and Address
        Person(std::string firstName, std::string lastName, Address address)
                : m_firstName{std::move(firstName)}
                , m_lastName{std::move(lastName)}
                , m_address{std::move(address)} {}

        // getter methods
        const std::string& getFirstName() const     {   return m_firstName; }
        const std::string& getLastName() const      {   return m_lastName;  }
        const Address& getAddress() const           {   return m_address;   }
};
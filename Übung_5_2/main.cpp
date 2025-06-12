#include <string>
#include <iostream>
#include "Address.h"
#include "Person.h"
#include "University.h"
#include "Faculty.h"

int main() {
    Person pres {"Präsident", "Hochschule", Address{"Straße", "Stadt", "Land"}};

    University uni {"Uni Name", Address{"Bahnhofstrasse", "Kempten", "Deutschland"}, &pres};

    Faculty inf {"Fakultät Informatik", &uni};

    Faculty soc {"Fakultät Soziale Arbeit", &uni};

    uni.addFaculty(&inf);

    Person prof {"Prof Theo", "Informatik", Address{"Straße", "Stadt", "Land"}};

    Person stud {"Mii", "Serable", Address{"Straße", "Stadt", "Land"}};

    inf.addProfessor(&prof);
    inf.addStudent(&stud);

    std::cout << prof.getFirstName() << prof.getLastName() << std::endl;

    std::cout << uni.getAddress().getCity() << uni.getAddress().getStreet() << uni.getAddress().getCountry() << std::endl;

    std::cout << uni.getPresident()->getFirstName() << uni.getPresident()->getLastName() << uni.getPresident()->getAddress().getCity() << std::endl;

    std::cout << uni.getFaculty(0)->getStudent(0)->getFirstName() << uni.getFaculty(0)->getStudent(0)->getLastName() << std::endl;
}
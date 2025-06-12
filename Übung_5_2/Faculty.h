#pragma once
#include <string>
#include "University.h"
#include "Person.h"

class Faculty {
    public:
        // constructor
        Faculty(std::string name, University* university);

        // getter methods
        const std::string getName() const;
        University* getUniversity() const;
        Person* getProfessor(std::size_t index) const;
        std::size_t getProfessorCount() const;
        Person* getStudent(std::size_t index) const;
        std::size_t getStudentCount() const;

        void addProfessor(Person* professor);
        void removeProfessor(Person* professor);

        void addStudent(Person* student);
        void removeStudent(Person* student);


    private:
        std::string m_name;
        University* m_university;
        Person* m_professors[10];
        Person* m_students[500];
};
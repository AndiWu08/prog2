#include <string>
#include "Faculty.h"

Faculty::Faculty(std::string name, University* university) 
    : m_name{std::move(name)}
    , m_university{university}
    , m_professors{}
    , m_students{} 
{}

const std::string Faculty::getName() const {
    return m_name;
}

University* Faculty::getUniversity() const {
    return m_university;
} 

Person* Faculty::getProfessor(std::size_t index) const {
    return m_professors[index];
}

std::size_t Faculty::getProfessorCount() const {
    return sizeof(m_professors) / sizeof(m_professors[0]);
}

Person* Faculty::getStudent(std::size_t index) const {
    return m_students[index];
}

std::size_t Faculty::getStudentCount() const {
    return sizeof(m_students) / sizeof(m_students[0]);
}

void Faculty::addProfessor(Person* professor) {
    for (size_t i = 0; i < getProfessorCount(); i++)
    {
        if (m_professors[i] == nullptr)
        {
            m_professors[i] = professor;
            break;
        }
    }
}

void Faculty::removeProfessor(Person* professor) {
    for (size_t i = 0; i < getProfessorCount(); i++)
    {
        if (m_professors[i] == professor)
        {
            m_professors[i] = nullptr;
            break;
        }
    }
}

void Faculty::addStudent(Person* student) {
    for (size_t i = 0; i < getStudentCount(); i++)
    {
        if (m_students[i] == nullptr)
        {
            m_students[i] = student;
            break;
        }
    }
}

void Faculty::removeStudent(Person* student) {
    for (size_t i = 0; i < getStudentCount(); i++)
    {
        if (m_students[i] == student)
        {
            m_students[i] = nullptr;
            break;
        }
    }
}
#pragma once
#include <iostream>

class Vector
{
    public:
        explicit Vector();  // Standardkonstruktor (m_size = 0)
        explicit Vector(unsigned size); // (m_size = size)

        // Kopierkonstruktor
        Vector(const Vector& other);

        // Kopier-Zuweisung
        Vector& operator= (const Vector& other);

        // Verschiebungskonstruktor
        Vector(Vector&& other);     // && -> nur R-Values akzeptiert, keine aus Versehen Verschiebung findet statt

        // Verschiebungszuweisung
        Vector& operator= (Vector&& other);
        
        ~Vector(); // Destruktor

        // getter functions
        unsigned getSize() const;

        // setter functions
        void setSize(unsigned size);

        // add value to the end of the array
        void pushBack(const double& val);

        // operator[] überschreiben und Element an stelle zurückbekommen
        double& operator[] (unsigned id);
        const double& operator[] (unsigned id) const;

        // selbe funktion wie [] mit Überprüfung ob Element im array existiert, sonst oberstes element zurück
        double& at(unsigned id);

        // add elements of v to this vectors elements
        // if v is larger, the remaining elements are ignored
        Vector& operator+= (const Vector& v);

        // subtract elements of v to this vectors elements
        // if v is larger, the remaining elements are ignored
        Vector& operator-= (const Vector& v);

        // multiply elements of v to this vectors elements
        // if v is larger, the remaining elements are ignored
        Vector& operator*= (const Vector& v);

        // add val to every element
        Vector& operator+= (const double val);

        // subtract val from every element
        Vector& operator-= (const double val);

        // multiply every element with val
        Vector& operator*= (const double val);

    private:
        unsigned m_size; // size of array
        double *m_elements; // Array of doubles
};

// lhs < rhs => -1; lhs == rhs => 0; lhs > rhs => 1;
int operator<=>(const Vector& lhs, const Vector& rhs);

// for better performance implement == seperately as well
bool operator==(const Vector& lhs, const Vector& rhs);

std::ostream& operator<< (std::ostream& os, const Vector& v);

std::istream& operator>> (std::istream& is, Vector& v);

// add v1 + v2 and put result in new vector
Vector operator+ (const Vector &v1, Vector &v2);

Vector operator- (const Vector &v1, Vector &v2);

// Skalarprodukt
double operator* (const Vector &v1, const Vector &v2);
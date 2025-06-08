#include "Vector.h"
#include <cstring>

// Standardkonstruktor
Vector::Vector()
    : m_elements{nullptr}
    , m_size{0}
{}

// Konstruktor mit Größe des Arrays
Vector::Vector(unsigned size)
    : m_elements{new double[size]} // array der Größe size erstellen
    , m_size{size}
{
    // alle Elemente mit 0 initialisieren
    for (int i = 0; i < size; i++)
    {
        m_elements[i] = 0;
    }
}

Vector::Vector(const Vector& other) 
    : m_elements{new double[other.getSize()]}
    , m_size{other.getSize()}
{
    memcpy(m_elements, other.m_elements, sizeof(double) * m_size);
}

Vector& Vector::operator= (const Vector& other) {
    // check if the copy is of itself
    if (this != &other)
    {
        delete[] m_elements;
        m_elements = new double[other.getSize()];
        m_size = other.getSize();
        memcpy(m_elements, other.m_elements,sizeof(double) * other.getSize());
    }
    return *this;
}

Vector::Vector(Vector&& other)
    : m_elements{other.m_elements}  // alte Pointer werden für neuen Vektor übernommen, kein neues festlegen von Speicher notwendig
    , m_size{other.getSize()}    
{
    // point old vector to 0
    other.m_elements = nullptr;
    other.m_size = 0;
}

Vector& Vector::operator= (Vector&& other) {
    // check if it references itself
    if (this != &other)
    {
        // set new values
        m_elements = other.m_elements;
        m_size = other.m_size;

        // set values of other to 0
        other.m_elements = nullptr;
        other.m_size = 0;
    }
    return *this;    
}

Vector::~Vector() {
    // delete if m_elements existst (!= nullptr)
    delete[] m_elements;
    std::cout << "Destruktor aufgerufen" << std::endl;
}

// getter functions
unsigned Vector::getSize() const {
    return m_size;
}

// setter functions
void Vector::setSize(unsigned size) {
    if (size == m_size)
    {
        return ;
    }
    
    // neue Größe festlegen, wenn bisher nur nullptr existiert
    if (!m_elements)
    {
        // neue Größe festlegen
        m_size = size;
        m_elements = new double[size];

        // Elemente initialisieren
        for (int i = 0; i < size; i++)
        {
            m_elements[i] = 0;
        }
        return ;
    }
    
    // neuen Speicher festlegen
    double *new_elements = new double[size];

    // speichert den kleineren Wert
    int minSize = std::min(size, m_size);

    // memcpy(destination, source, count (how many bytes to copy)
    // Elemente werden von m_elements nach new_elements kopiert
    // minSize*sizeof(double) => wieviele Elemente übertragen werden sollen
    std::memcpy(new_elements, m_elements, minSize*sizeof(double));

    // wenn der neue Array größer ist, müssen die restlichen Werte mit 0 initialisiert werden
    for (int i = minSize; i < size; i++)
    {
        new_elements[i] = 0;
    }

    // alten array löschen und neue Werte setzen
    delete[] m_elements;
    m_elements = new_elements;
    m_size = size;
}

double& Vector::operator[] (unsigned id) {
    return m_elements[id];
}

const double& Vector::operator[] (unsigned id) const{
    return m_elements[id];
}

double& Vector::at(unsigned id) {
    if (id <= m_size)
    {
        return m_elements[id];
    }
    else
    {
        return m_elements[0];
    }
    
}

void Vector::pushBack(const double& val) {
    // increase size 
    setSize(m_size + 1);
    
    // set value of last element
    m_elements[m_size - 1] = val;
}

int operator<=>(const Vector &lhs, const Vector &rhs)
{
    // first check, if one is bigger than the other
    auto lSize = lhs.getSize();
    auto rSize = rhs.getSize();
    if (lSize != rSize)
    {
        return (lSize < rSize) 
        ? -1    // lhs smaller 
        : 1;    // lhs bigger
    }

    // both vektors are the same size -> compare values
    for (int i = 0; i < lSize; i++)
    {
        if (lhs[i] != rhs[i])
        {
            return (lhs[i] < lhs[i]) 
            ? -1    // true (lhs smaller)
            : 1;    // false (lhs bigger)
        }
    }
    // if we reached this point, vektors are the same
    return 0;
}

bool operator==(const Vector &lhs, const Vector &rhs)
{
    // if the vectors aren't the same size they can't be equal
    if (lhs.getSize() != rhs.getSize())
    {
        return false;
    }

    for (int i = 0; i < lhs.getSize(); i++)
    {
        // return false if differet
        if (lhs[i] != rhs[i])
        {
            return false;
        }
    }
    // every item is the same
    return true;
}

// output values of vector with space in between
std::ostream& operator<< (std::ostream& os, const Vector& v) {
    os << "(";
    for (int i = 0; i < v.getSize(); i++)
    {
        os << v[i] << " ";
    }
    return os << ")";
}

std::istream& operator>> (std::istream& is, Vector& v) {
    // only read as many values as vectors size
    for (int i = 0; i < v.getSize(); i++)
    {
        // leave loop if unvalid value
        if (!(is >> v[i]))
        {
            break;
        }
    }
    return is;
}

Vector operator+ (const Vector &v1, Vector &v2) {
    int minSize = std::min(v1.getSize(), v2.getSize());
    int maxSize = std::max(v1.getSize(), v2.getSize());

    Vector resultVector(maxSize);

    // add values for the size of smaller vector
    for (int i = 0; i < minSize; i++)
    {
        resultVector[i] = v1[i] + v2[i];
    }

    // copy elements of bigger vector in result
    memcpy(&resultVector[0] + minSize
        , (v1.getSize() > v2.getSize()) ? &v1[minSize] : &v2[minSize], 
        sizeof(double) * (maxSize - minSize));

    return resultVector;
}

Vector operator- (const Vector &v1, Vector &v2) {
    int minSize = std::min(v1.getSize(), v2.getSize());
    int maxSize = std::max(v1.getSize(), v2.getSize());

    Vector resultVector(maxSize);

    // subtract values
    for (int i = 0; i < minSize; i++)
    {
        resultVector[i] = v1[i] - v2[i];
    }  
    
    // fill remainign values accordingly
    if (v1.getSize() < v2.getSize())
    {   
        // v2 is bigger so result is negative value of v2
        for (int i = minSize; i < maxSize; i++)
        {
            resultVector[i] = -v2[i];
        }
        
    }
    else if (v1.getSize() > v2.getSize())
    {
        // v1 is bigger so result is value of v1
        for (int i = minSize; i < maxSize; i++)
        {
            resultVector[i] = v1[i];
        }
    }
    return resultVector;   
}

double operator* (const Vector &v1, const Vector &v2) {
    auto minSize = std::min(v1.getSize(), v2.getSize());

    double scalarProduct = 0.0;
    for (int i = 0; i < minSize; i++)
    {
        scalarProduct += v1[i] * v2[i];
    }
    return scalarProduct;
}

Vector& Vector::operator+= (const Vector& v) {
    unsigned minSize = std::min(m_size, v.getSize());

    for (unsigned i = 0; i < minSize; i++)
    {
        m_elements[i] += v[i];
    }
    return *this;
}

Vector& Vector::operator-= (const Vector& v) {
    unsigned minSize = std::min(m_size, v.getSize());

    for (unsigned i = 0; i < minSize; i++)
    {
        m_elements[i] -= v[i];
    }
    return *this;
}


Vector& Vector::operator*= (const Vector& v) {
    unsigned minSize = std::min(m_size, v.getSize());

    for (unsigned i = 0; i < minSize; i++)
    {
        m_elements[i] *= v[i];
    }
    return *this;
}

Vector& Vector::operator*= (const double val) {
    for (unsigned i = 0; i < m_size; i++)
    {
        m_elements[i] *= val;
    }
    return *this;
}

Vector& Vector::operator+= (const double val) {
    for (unsigned i = 0; i < m_size; i++)
    {
        m_elements[i] += val;
    }
    return *this;
}

Vector& Vector::operator-= (const double val) {
    for (unsigned i = 0; i < m_size; i++)
    {
        m_elements[i] -= val;
    }
    return *this;
}
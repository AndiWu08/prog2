#include <iostream>
#include "Vector.h"
#include "TestCopy.hpp"
#include "TestMove.hpp"
#include "TestAssign.hpp"

int main() {
    // for exercise 2
    Vector v1;
    Vector v2(10);

    std::cout << "v1: " << v1.getSize() << std::endl;
    std::cout << "v2: " <<  v2.getSize() << std::endl;

    std::cout << ((v1 == v2) ? "same size" : "different size") << std::endl;
    std::cout << ((v1 < v2) ? "v1 is smaller" : "v1 isn't smaller") << std::endl;
    std::cout << ((v1 > v2) ? "v2 is smaller" : "v2 isn't smaller") << std::endl;

    v1.setSize(3);
    v2.setSize(2);

    std::cout << ((v1 == v2) ? "vectors are equal" : "vectors aren't equal") << std::endl;
    std::cout << ((v1 < v2) ? "v1 is smaller" : "v1 isn't smaller") << std::endl;
    std::cout << ((v1 > v2) ? "v2 is smaller" : "v2 isn't smaller") << std::endl;

    std::cout << "v1: " << v1.getSize() << std::endl;
    std::cout << "v2: " <<  v2.getSize() << std::endl;

    std::cout << v1[1] << std::endl;
    std::cout << v1.at(0) << std::endl;
    std::cout << v1.at(100) << std::endl;

    // std::cin >> v1; // comment to speed up testing
    v1.pushBack(5.0);
    v2.pushBack(5.0);
    v2.pushBack(5.0);
    v2.pushBack(5.0);
    v2.pushBack(5.0);
    v2.pushBack(5.0);

    std::cout << ((v1 == v2) ? "vectors are equal" : "vectors aren't equal") << std::endl;
    std::cout << ((v1 < v2) ? "v1 is smaller" : "v1 isn't smaller") << std::endl;
    std::cout << ((v1 > v2) ? "v2 is smaller" : "v2 isn't smaller") << std::endl;

    Vector v3 = v1 + v2;
    Vector v4 = v1 - v2;

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << v3 << std::endl;
    std::cout << v4 << std::endl;
    std::cout << "Skalar <v1, v2> = " << v1*v2 << std::endl;
    std::cout << "Skalar <v1, v3> = " << v1*v3 << std::endl;

    v3-=2.0;
    std::cout << "v3: " << v3 << std::endl;
    v3+=2.0;
    std::cout << "v3: " << v3 << std::endl;
    v3*=2.0;
    std::cout << "v3: " << v3 << std::endl;

    std::cout << "v4: " << v4 << std::endl;
    v4+=v1;
    std::cout << "v4: " << v4 << std::endl;
    v4-=v1;
    std::cout << "v4: " << v4 << std::endl;
    v4*=v1;
    std::cout << "v4: " << v4 << std::endl;

    // for exercise 3
    Vector v5{v2};
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v5: " << v5 << std::endl;
    v2.pushBack(3.0);
    v2.pushBack(2.0);
    v5.pushBack(7.0);
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v5: " << v5 << std::endl;
    
    std::cout << "v1: " << v1 << std::endl;
    v1 = v5;
    std::cout << "v1: " << v1 << std::endl;

    std::cout << "--- Test Copy ---" << std::endl;
    testCopy();

    std::cout << "--- Test Move ---" << std::endl;
    testMove();

    std::cout << "--- Test Assign ---" << std::endl;
    testAssign();
}


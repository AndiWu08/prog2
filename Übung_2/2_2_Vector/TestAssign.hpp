#include <iostream>
#include "Vector.h"

void testAssign()
{
	Vector v1;
	v1.pushBack(1);
	v1.pushBack(2);
	v1.pushBack(3);
	std::cout << "V1: " << v1 << std::endl;

	v1 = v1;
	std::cout << "V1: " << v1 << std::endl;
}
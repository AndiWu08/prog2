#include <iostream>
#include "Vector.h"

void testMove()
{
	Vector v1;
	v1.pushBack(1);
	v1.pushBack(2);
	v1.pushBack(3);
	v1.pushBack(5);

	Vector v2 = std::move(v1);

	Vector v3;
	v3.pushBack(8);
	v3.pushBack(13);
	v3.pushBack(21);
	v1 = std::move(v3);
	v3.pushBack(34);

	std::cout << "V1: " << v1 << std::endl
		<< "V2: " << v2 << std::endl
		<< "V3: " << v3 << std::endl;
}
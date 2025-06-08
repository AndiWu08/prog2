#include <iostream>

int main()
{
	std::string input;
	std::cin >> input;
	uint16_t sum = 0;
	for (char c : input)
		sum += c - 48;
	std::cout << sum;
}
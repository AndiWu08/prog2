#include <iostream>

int main()
{
	std::cout << "Please enter your first and second names and your age\n";
	std::string first;
	std::string second;
	double age;

	std::cin >> first >> second >> age;

	std::cout << "\n Hello, " << first << " " << second << " " << age << std::endl;

}
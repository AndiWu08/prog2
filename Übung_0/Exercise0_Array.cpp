#include <iostream>
#include <cstdint>

bool compReference(const int& lhs, const int& rhs)
{
	return lhs < rhs;
}

bool compPointer(const int* const lhs, const int* const rhs)
{
	return lhs < rhs;
}

bool compCopy(int lhs, int rhs)
{
	return lhs < rhs;
}

void initial_main() {
	int a1[5] = { 1, 2, 3, 4, 5 };
	int a2[3] = { 3, 2, 1 };

	for (int i = 0; i < 3; ++i)
		std::cout <<
		"Values: " << *(a1 + i) << ", " << *(a2 + i) << '\n' <<
		"Compare by Reference: " << compReference(*(a1 + i), *(a2 + i)) << '\n' <<
		"Compare by Copy: " << compCopy(*(a1 + i), *(a2 + i)) << '\n' <<
		"Compare by Pointer: " << compPointer(a1 + i, a2 + i) << '\n' <<
		'\n';
}

enum class ExperienceLevel
{
	Intern,
	Entry,
	Intermediate,
	Senior
};

struct Employee
{
	std::string name;
	uint8_t yearsInCompany;
	ExperienceLevel level;
};

void printEmployee(const Employee &employee) {
	std::cout << "Name: " << employee.name;

	std::cout << " Experience Level: ";
	switch (employee.level)
	{
	case ExperienceLevel::Intern:
		std::cout << "Intern";
		break;
	case ExperienceLevel::Entry:
		std::cout << "Entry";
		break;
	case ExperienceLevel::Intermediate:
		std::cout << "Intermediate";
		break;
	case ExperienceLevel::Senior:
		std::cout << "Senior";
		break;
	
	default:
		std::cout << "?unknown?";
	}

	std::cout << " time at compay:" << std::to_string(employee.yearsInCompany) << ((employee.yearsInCompany == 1) ? " year" : " years");
	std::cout << std::endl;
}

void printEmployeeArray(Employee list[], int size) {
	std::cout << "Employee Array: \n";
	for (int i = 0; i < size; i++)
	{
		printEmployee(list[i]);
	}
	std::cout << "end of array" << std::endl;
}

int main()
{
	Employee hans{
		"Hans Wurst",
		5,
		ExperienceLevel::Intermediate,
	};
	printEmployee(hans);

	Employee list[]{
		hans,
		{"Max Mustermann", 10, ExperienceLevel::Senior},
		{"Maria Müller", 2, ExperienceLevel::Intermediate}
	};
	printEmployeeArray(list, 3);
}
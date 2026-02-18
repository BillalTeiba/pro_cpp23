#include "employee.h"
#include <iostream>

using namespace std;

int main()
{
	// Create and populate an employee using designated initializers.
	HR::Employee anEmployee {
		.firstInitial = 'J',
		.lastInitial = 'D',
		.employeeNumber = 42,
		.salary = 80'000
	};

	// Print the values of an employee
	cout << "Employee: " << anEmployee.firstInitial << anEmployee.lastInitial << '\n';
	cout << "Number: " << anEmployee.employeeNumber << '\n';
	cout << "Salary: $" << anEmployee.salary << '\n';
}

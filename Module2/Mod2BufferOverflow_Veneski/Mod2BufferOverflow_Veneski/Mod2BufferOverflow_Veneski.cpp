// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Edits made by Joseph Veneski 3/11/2024
// CS405 Secure Coding

#include <iomanip>
#include <iostream>

int main()
{
	std::cout << "Buffer Overflow Example" << std::endl;

	// TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
	//  even though it is a constant and the compiler buffer overflow checks are on.
	//  You need to modify this method to prevent buffer overflow without changing the account_order
	//  variable, and its position in the declaration. It must always be directly before the variable used for input.

	const std::string account_number = "CharlieBrown42";
	char user_input[20];
	std::cout << "Enter a value: ";

	// Use getline to be able to specify the number of characters read from stream
	// reads input until "/n" is found or sizeof(user_input)-1 characters are entered
	// leaves room for the null terminator
	// https://cplusplus.com/reference/istream/istream/getline/
	std::cin.getline(user_input, sizeof(user_input));

	std::cout << "You entered: " << user_input << std::endl;
	std::cout << "Account Number = " << account_number << std::endl;
}
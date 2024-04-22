// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Edits made by Joseph Veneski 
// March 30, 2024
// CS-405 Secure Coding

#include <iostream>
#include <stdexcept> // needed for exceptions

// custom exception class derived from std::exception
class CustomException : public std::exception {
public:
    // override what method to return custom message
    const char* what() const noexcept override {
        return "Custom exception occurred";
    }
};

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception
    throw std::runtime_error("A standard exceptioin occurred in do_even_more_custom_application_logic");

    std::cout << "Running Even More Custom Application Logic." << std::endl;
    return true;
}

void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    try {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (const std::exception& e) {
        // catch standard exceptions
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main
    throw CustomException();

    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    if (den == 0) { // cannot divide by zero, check denominator
        throw std::domain_error("Attempted to divide by zero"); 
    }
    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    try {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    } 
    catch (const std::exception& e) {
        // handle exception thrown by divide()  
        std::cout << "Exception caught in do_division: " << e.what() << std::endl;
    }
}

int main()
{
    // try block around main
    try {
        std::cout << "Exceptions Tests!" << std::endl;

        // TODO: Create exception handlers that catch (in this order):
        //  your custom exception
        //  std::exception
        //  uncaught exception 
        //  that wraps the whole main function, and displays a message to the console.
        do_division();
        do_custom_application_logic();
    }
    catch (const CustomException& e) { 
        // catch custom exceptions
        std::cout << "CustomException caught: " << e.what() << std::endl;
    }
    catch (const std::exception& e) { 
        // catch standard exceptions
        std::cout << "Standard Exception caught: " << e.what() << std::endl;
    }
    catch (...) { 
        // catch-all for all unhandled excpetions
        std::cout << "Unknown exception caught" << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
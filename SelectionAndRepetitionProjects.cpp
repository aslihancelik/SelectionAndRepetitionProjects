// SelectionAndRepetitionProjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// This program mimics a simple calculator. It takes two integers and an operator as input from the user
// and performs the specified arithmetic operation (+, -, *, /). The user can also choose to exit the program
// by typing "exit". If the input format is incorrect, the program prompts the user to try again or exit.
// It handles division by zero and provides appropriate error messages.
//
//Programmer: Aslihan Celik


#include <iostream>
#include <string>
#include <sstream>  // For stringstream
#include <limits>   // For clearing input errors
using namespace std;

int main()
{
    int number1, number2; // Variables to store the two numbers for calculations
    char operatorSelected, exitChoice;  // Variables for the operator and exit choice
    string userInput; // String to hold the user's input

    do {

        // Display instructions for the user
        cout << "Please enter the calculation you would like to make as:" << endl;
        cout << "number operator number " << endl << "(e.g. 5 + 5 or 6 / 1)" << endl;
        cout << "using one of the following operators : " << endl;
        cout << "+ for summation" << endl << "- for subtraction" << endl << "/ for division " << endl << "* for multiplication" << endl;
        cout << "Or type 'exit' to quit." << endl;
        cout << "Then press enter." << endl;

        // Get the entire line of input ( e.g. "5 + 10" or "exit" )
        getline(cin, userInput);

        // Check if the user wants to exit the program
        if (userInput == "exit") {
            cout << "Exiting the program..." << endl;
            break; // Exit the loop
        }

        // Use a stringstream to parse the input into components
        //create a stringstream object called sStream which holds the content of iserInput
        stringstream sStream(userInput);

        // we can now extract each part of the string(the numbers and the operator) 
        // using the extraction operator ( >> ), just like we would do with cin for console input.
        // extract the first number, the operator, and the second number
        // If extraction was successful, perform the calculation based on the operator
        if (sStream >> number1 >> operatorSelected >> number2) {

            //check if entered correct

            switch (operatorSelected) {
            case '+':
                cout << number1 << " + " << number2 << " = " << number1 + number2 << endl;
                break;
            case '-':
                cout << number1 << " - " << number2 << " = " << number1 - number2 << endl;
                break;
            case '*':
                cout << number1 << " * " << number2 << " = " << number1 * number2 << endl;
                break;
            case '/':
                //check the denominator, it shouldn't be zero
                if (number2 != 0) {
                    cout << number1 << " / " << number2 << " = " << number1 / number2 << endl;
                }
                else {
                    cout << "Error: Division by zero is undefined." << endl;
                }
                break;
            default:
                cout << " Error: Unknown operator.";
                break;
            }
        }
        else {
            // If input format was incorrect, display an error message
            cout << "Error: Invalid input format. Please enter in the correct format (e.g., 5 + 5)." << endl;

            // Prompt the user to decide if they want to exit or retry
            cout << "Would you like to try again? (y/n): ";
            cin >> exitChoice;

            // Clear the input stream in case of leftover invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover input

            // Check user's choice to either exit or continue
            if (exitChoice == 'n' || exitChoice == 'N') {
                cout << "Exiting the program..." << endl;
                break;  // Exit the loop and the program
            }
            // If the user wants to retry, the loop continues without needing to clear input again  
        }
    } while (true); // Repeat until the user chooses to exit

    return 0;
}

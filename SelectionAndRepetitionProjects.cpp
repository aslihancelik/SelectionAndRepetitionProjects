// SelectionAndRepetitionProjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//

#include <iostream>
using namespace std;

int main()
{
    int number1, number2;
    char operatorSelected;

    cout << "Please enter the calculation you would like to make as:"  << endl;
    cout << "number operator number " << endl << "(e.g. 5 + 5 or 6 / 1)" << endl;
    cout << "using one of the following operators : " << endl;
    cout << "+ for summation" << endl << "- for subtraction" << endl << "/ for division " << endl << "* for multiplication" << endl;
    cout << "Then press enter.";

    cin >> number1 >> operatorSelected >> number2;
    //check if entered correct

    do {
        switch (operatorSelected) {
        case '+':
            break;
        case '-':
            break;
        case '*':
            break;
        case '/':
            break;
        default:
            cout << " Unknown operator.";
            break;
        }
    } while();

    return 0;
}

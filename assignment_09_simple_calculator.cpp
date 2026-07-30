// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// =============================================================================

// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


// -----------------------------------------------------------------------------
// FUNCTION 1 — Addition
// -----------------------------------------------------------------------------

void addition(double a, double b) {

    cout << fixed << setprecision(2);

    cout << "Result: "
         << a << " + " << b
         << " = " << (a + b)
         << endl;
}


// -----------------------------------------------------------------------------
// FUNCTION 2 — Subtraction
// -----------------------------------------------------------------------------

void subtraction(double a, double b) {

    cout << fixed << setprecision(2);

    cout << "Result: "
         << a << " - " << b
         << " = " << (a - b)
         << endl;
}


// -----------------------------------------------------------------------------
// FUNCTION 3 — Multiplication
// -----------------------------------------------------------------------------

void multiplication(double a, double b) {

    cout << fixed << setprecision(2);

    cout << "Result: "
         << a << " * " << b
         << " = " << (a * b)
         << endl;
}


// -----------------------------------------------------------------------------
// FUNCTION 4 — Division
// -----------------------------------------------------------------------------

void division(double a, double b) {

    if (b == 0) {

        cout << "Error: Cannot divide by zero." << endl;

        return;
    }


    cout << fixed << setprecision(2);

    cout << "Result: "
         << a << " / " << b
         << " = " << (a / b)
         << endl;
}


// -----------------------------------------------------------------------------
// FUNCTION 5 — Modulus
// -----------------------------------------------------------------------------

void modulus(double a, double b) {

    if (b == 0) {

        cout << "Error: Cannot divide by zero." << endl;

        return;
    }


    int first = static_cast<int>(a);

    int second = static_cast<int>(b);


    cout << "Result: "
         << first << " % " << second
         << " = " << (first % second)
         << endl;
}


// -----------------------------------------------------------------------------
// FUNCTION 6 — Exponentiation
// -----------------------------------------------------------------------------

void exponentiation(double a, double b) {

    if (b < 0) {

        cout << "Error: Exponent must be non-negative."
             << endl;

        return;
    }


    double result = 1;

    int exponent = static_cast<int>(b);


    for (int i = 0; i < exponent; i++) {

        result *= a;

    }


    cout << fixed << setprecision(2);

    cout << "Result: "
         << a << " ^ " << b
         << " = " << result
         << endl;
}


// -----------------------------------------------------------------------------
// MAIN FUNCTION
// -----------------------------------------------------------------------------

int main() {


    int choice;



    do {


        cout << endl;

        cout << "============================" << endl;
        cout << "     SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;

        cout << "1. Addition" << endl;

        cout << "2. Subtraction" << endl;

        cout << "3. Multiplication" << endl;

        cout << "4. Division" << endl;

        cout << "5. Modulus" << endl;

        cout << "6. Exponentiation" << endl;

        cout << "7. Quit" << endl;


        cout << "Select an operation (1-7): ";

        cin >> choice;



        if (choice >= 1 && choice <= 6) {


            double first;

            double second;


            cout << "Enter first number: ";

            cin >> first;


            cout << "Enter second number: ";

            cin >> second;



            switch(choice) {


                case 1:

                    addition(first, second);

                    break;



                case 2:

                    subtraction(first, second);

                    break;



                case 3:

                    multiplication(first, second);

                    break;



                case 4:

                    division(first, second);

                    break;



                case 5:

                    modulus(first, second);

                    break;



                case 6:

                    exponentiation(first, second);

                    break;

            }


        } 
        else if (choice == 7) {


            cout << "Goodbye!" << endl;


        } 
        else {


            cout << "Error: Invalid choice." << endl;


        }



    } while (choice != 7);



    return 0;

}
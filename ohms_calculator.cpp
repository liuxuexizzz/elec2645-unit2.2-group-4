#include "ohms_calculator.h"
#include "Basic_op.h"
#include "input_functions.h"
#include <iostream>
using namespace std;



/* 
Function:       calculateOhmsLaw
Input:          Two of current, resistance, or voltage
Output:         The other one
Description:    Provides an interface for users to calculate voltage, current, or resistance 
                using Ohm's Law: V = I * R.
*/
void calculateOhmsLaw() {
    cout << "Welcome to Ohm's Law Calculator!\n";
    cout << "Please select the quantity to calculate:\n";
    cout << "1. Voltage (V)\n2. Current (I)\n3. Resistance (R)\n";

    int choice = getIntInput();

    double V = 0.0, I = 0.0, R = 0.0, result = 0.0;
    basic_op status;

    switch (choice) {
        case 1:                 // Calculate Voltage: V = I * R
            cout << "Enter Current (I in Amperes): ";
            I = getDoubleInput();

            cout << "Enter Resistance (R in Ohms): ";
            R = getDoubleInput();

            status = calculate(I, R, '*', result);
            if (status == basic_op::SUCCESS) {
                cout << "Voltage (V) = " << result << " Volts\n";
            } else {
                cout << getErrorMessage(status) << endl;
            }
            break;



        case 2:                 // Calculate Current: I = V / R
            cout << "Enter Voltage (V in Volts): ";
            V = getDoubleInput();

            cout << "Enter Resistance (R in Ohms): ";
            R = getDoubleInput();

            status = calculate(V, R, '/', result);
            if (status == basic_op::SUCCESS) {
                cout << "Current (I) = " << result << " Amperes\n";
            } else {
                cout << getErrorMessage(status) << endl;
            }
            break;



        case 3:                 // Calculate Resistance: R = V / I
            cout << "Enter Voltage (V in Volts): ";
            V = getDoubleInput();

            cout << "Enter Current (I in Amperes): ";
            I = getDoubleInput();

            status = calculate(V, I, '/', result);
            if (status == basic_op::SUCCESS) {
                cout << "Resistance (R) = " << result << " Ohms\n";
            } else {
                cout << getErrorMessage(status) << endl;
            }
            break;



        default:
            cout << "Invalid choice. Please restart the program.\n";
            break;
    }

    cout << "Thank you for using Ohm's Law Calculator!\n";
}

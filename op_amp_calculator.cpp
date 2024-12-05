#include "op_amp_calculator.h"
#include <iostream>
#include <limits>  // For numeric_limits to clear input buffer

using namespace std;



/* 
Function:       op_amp_main_menu
Input:          None
Output:         None
Description:    Presents the operational amplifier calculation menu to the user and directs to specific calculation functions.
*/
void op_amp_main_menu() {
    int op_amp_input;
    do {
        cout << "\n----- Operational Amplifier Calculation Menu -----\n";
        cout << "1. Inverting Amplifier Gain Calculation\n";
        cout << "2. Non-inverting Amplifier Gain Calculation\n";
        cout << "3. Differential Amplifier Gain Calculation\n";
        cout << "4. Integrator Amplifier Calculation\n";
        cout << "5. Differentiator Amplifier Calculation\n";
        cout << "6. Low-pass Filter Calculation\n";
        cout << "7. High-pass Filter Calculation\n";
        cout << "8. Return to Main Menu\n";
        cout << "Please choose an option (1-8): ";
        cin >> op_amp_input;

        if (cin.fail()) {
            // Handle non-integer inputs
            cin.clear();  // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "Invalid input. Please enter an integer between 1 and 8." << endl;
            continue;
        }

        switch (op_amp_input) {
            case 1:
                calculate_inverting_gain();
                break;
            case 2:
                calculate_non_inverting_gain();
                break;
            case 3:
                calculate_differential_gain();
                break;
            case 4:
                calculate_integrator_gain();
                break;
            case 5:
                calculate_differentiator_gain();
                break;
            case 6:
                calculate_low_pass_filter();
                break;
            case 7:
                calculate_high_pass_filter();
                break;
            case 8:
                return;
            default:
                cout << "Invalid selection, please try again.\n";
        }
    } while (op_amp_input != 8);
}



/* 
Function:       calculate_inverting_gain
Input:          None
Output:         None
Description:    Calculates the gain of an inverting amplifier.
*/
void calculate_inverting_gain() {
    double Rf = get_resistor_value(std::string("feedback resistor Rf (Ω)"));
    double Rin = get_resistor_value(std::string("input resistor Rin (Ω)"));

    if (Rf > 0 && Rin > 0) {
        double gain = -Rf / Rin;
        cout << "Inverting amplifier gain: " << gain << endl;
    } else {
        cout << "Invalid resistor values. Both resistors must be greater than zero." << endl;
    }
}



/* 
Function:       calculate_non_inverting_gain
Input:          None
Output:         None
Description:    Calculates the gain of a non-inverting amplifier.
*/
void calculate_non_inverting_gain() {
    double Rf = get_resistor_value(std::string("feedback resistor Rf (Ω)"));
    double Rin = get_resistor_value(std::string("input resistor Rin (Ω)"));

    if (Rf > 0 && Rin > 0) {
        double gain = 1 + (Rf / Rin);
        cout << "Non-inverting amplifier gain: " << gain << endl;
    } else {
        cout << "Invalid resistor values. Both resistors must be greater than zero." << endl;
    }
}



/* 
Function:       calculate_differential_gain
Input:          None
Output:         None
Description:    Calculates the gain of a differential amplifier.
*/
void calculate_differential_gain() {
    double Rf = get_resistor_value(std::string("feedback resistor Rf (Ω)"));
    double Rin = get_resistor_value(std::string("input resistor Rin (Ω)"));

    if (Rf > 0 && Rin > 0) {
        double gain = Rf / Rin;
        cout << "Differential amplifier gain: " << gain << endl;
    } else {
        cout << "Invalid resistor values. Both resistors must be greater than zero." << endl;
    }
}



/* 
Function:       get_resistor_value
Input:          const string& resistor_name // The name of the resistor to be input by the user
Output:         double      value          // The value of the resistor entered by the user
Description:    Prompts the user to enter a value for the specified resistor, with validation.
*/
double get_resistor_value(const std::string& resistor_name) {
    double value;
    do {
        cout << "\nEnter " << resistor_name << ": ";
        cin >> value;

        if (cin.fail() || value <= 0) {
            // Handle invalid or negative inputs
            cin.clear();  // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid value. Please enter a positive number.\n";
        } else {
            return value;
        }
    } while (true);
}



/* 
Function:       get_capacitor_value
Input:          const string& capacitor_name // The name of the capacitor to be input by the user
Output:         double      value            // The value of the capacitor entered by the user
Description:    Prompts the user to enter a value for the specified capacitor, with validation.
*/
double get_capacitor_value(const std::string& capacitor_name) {
    double value;
    do {
        cout << "\nEnter " << capacitor_name << ": ";
        cin >> value;

        if (cin.fail() || value <= 0) {
            // Handle invalid or negative inputs
            cin.clear();  // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid value. Please enter a positive number.\n";
        } else {
            return value;
        }
    } while (true);
}



/* 
Function:       calculate_integrator_gain
Input:          None
Output:         None
Description:    Calculates the gain of an integrator amplifier.
*/
void calculate_integrator_gain() {
    double R = get_resistor_value(std::string("input resistor R (Ω)"));
    double C = get_capacitor_value(std::string("capacitor C (F)"));

    if (R > 0 && C > 0) {
        double gain = -1 / (R * C);
        cout << "Integrator amplifier gain: " << gain << " s^-1" << endl;
    } else {
        cout << "Invalid component values. Both resistor and capacitor must be greater than zero." << endl;
    }
}



/* 
Function:       calculate_differentiator_gain
Input:          None
Output:         None
Description:    Calculates the gain of a differentiator amplifier.
*/
void calculate_differentiator_gain() {
    double R = get_resistor_value(std::string("feedback resistor R (Ω)"));
    double C = get_capacitor_value(std::string("capacitor C (F)"));

    if (R > 0 && C > 0) {
        double gain = -R * C;
        cout << "Differentiator amplifier gain: " << gain << " V/s" << endl;
    } else {
        cout << "Invalid component values. Both resistor and capacitor must be greater than zero." << endl;
    }
}



/* 
Function:       calculate_low_pass_filter
Input:          None
Output:         None
Description:    Calculates the cutoff frequency of a low-pass filter.
*/
void calculate_low_pass_filter() {
    double R = get_resistor_value(std::string("resistor R (Ω)"));
    double C = get_capacitor_value(std::string("capacitor C (F)"));

    if (R > 0 && C > 0) {
        double cutoff_frequency = 1 / (2 * 3.14159265358979 * R * C);
        cout << "Low-pass filter cutoff frequency: " << cutoff_frequency << " Hz" << endl;
    } else {
        cout << "Invalid component values. Both resistor and capacitor must be greater than zero." << endl;
    }
}



/* 
Function:       calculate_high_pass_filter
Input:          None
Output:         None
Description:    Calculates the cutoff frequency of a high-pass filter.
*/
void calculate_high_pass_filter() {
    double R = get_resistor_value(std::string("resistor R (Ω)"));
    double C = get_capacitor_value(std::string("capacitor C (F)"));

    if (R > 0 && C > 0) {
        double cutoff_frequency = 1 / (2 * 3.14159265358979 * R * C);
        cout << "High-pass filter cutoff frequency: " << cutoff_frequency << " Hz" << endl;
    } else {
        cout << "Invalid component values. Both resistor and capacitor must be greater than zero." << endl;
    }
}

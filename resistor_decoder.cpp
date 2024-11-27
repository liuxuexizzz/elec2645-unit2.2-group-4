#include "resistor_decoder.h"
#include "Get_user_input.h"
#include <iostream>
#include <map>
#include <cmath>
#include <string>

using namespace std;

// Maps and helper functions as before
const map<int, string> colorNames = {
    {0, "black"}, {1, "brown"}, {2, "red"}, {3, "orange"},
    {4, "yellow"}, {5, "green"}, {6, "blue"}, {7, "violet"},
    {8, "gray"}, {9, "white"}
};

const map<int, string> toleranceValues = {
    {1, "±1% (brown)"}, {2, "±2% (red)"}, {3, "±0.5% (green)"},
    {4, "±0.25% (blue)"}, {5, "±0.1% (violet)"}, {6, "±0.05% (gray)"},
    {7, "±5% (gold)"}, {8, "±10% (silver)"}
};

const map<int, string> multiplierValues = {
    {0, "×1 Ω (black)"}, {1, "×10 Ω (brown)"}, {2, "×100 Ω (red)"},
    {3, "×1 kΩ (orange)"},  {4, "×10 kΩ (yellow)"}, {5, "×100 kΩ (green)"},
    {6, "×1 MΩ (blue)"}, {7, "×10 MΩ (violet)"}, {8, "×100 MΩ (gray)"},
    {9, "×1 GΩ (white)"}, {10, "×0.1 Ω (gold)"}, {11, "×0.01 Ω (silver)"}
};



/* 
Function:       printColorCodeTable
Input:          None
Output:         None
Description:    Displays the color code table for resistors, showing the number and corresponding color.
*/
void printColorCodeTable() {
    cout << "\n----------- Color Code Table -----------\n";
    cout << "|  Resistance\t|\tColor\t|\n";
    cout << "----------------------------------------\n";
    for (const auto& entry : colorNames) {
        cout << "|\t" << entry.first << "\t|\t" << entry.second << "\t|\n";
    }
    cout << "----------------------------------------\n";
}



/* 
Function:       printMultiplierTable
Input:          None
Output:         None
Description:    Displays the multiplier table for resistors, showing the number and corresponding multiplier.
*/
void printMultiplierTable() {
    cout << "\n----------- Multiplier Table -----------\n";
    cout << "|\tNumber\t|\tMultiplier\t|\n";
    cout << "-----------------------------------------\n";
    for (const auto& entry : multiplierValues) {
        cout << "|\t" << entry.first << "\t|\t" << entry.second << "\t|\n";
    }
    cout << "-----------------------------------------\n";
}



/* 
Function:       printToleranceTable
Input:          None
Output:         None
Description:    Displays the tolerance table for resistors, showing the number and corresponding tolerance.
*/
void printToleranceTable() {
    cout << "\n----------- Tolerance Table ------------\n";
    cout << "|\tNumber\t|\tTolerance\t|\n";
    cout << "-----------------------------------------\n";
    for (const auto& entry : toleranceValues) {
        cout << "|\t" << entry.first << "\t|\t" << entry.second << "\t|\n";
    }
    cout << "-----------------------------------------\n";
}



/* 
Function:       decode4BandResistor
Input:          The color names corresponding to the four bands
Output:         Resistance decoding value
Description:    Decodes a 4-band resistor based on user input and displays the calculated resistance 
                along with the tolerance.
*/
void decode4BandResistor() {
    printColorCodeTable();
    cout << "Enter the first color: ";
    string color1 = getStringInput();
    cout << "Enter the second color: ";
    string color2 = getStringInput();
    
    printMultiplierTable();
    cout << "Enter the multiplier color: ";
    string color3 = getStringInput();
    
    printToleranceTable();
    cout << "Enter the tolerance color: ";
    string color4 = getStringInput();

    try {
        // Find the corresponding numbers for the colors
        int color1_num = -1, color2_num = -1, color3_num = -1, color4_num = -1;
        for (const auto& entry : colorNames) {
            if (entry.second == color1) color1_num = entry.first;
            if (entry.second == color2) color2_num = entry.first;
        }

        // Find the multiplier and tolerance values
        double multiplier;
        for (const auto& entry : multiplierValues) {
            if (entry.second.find(color3) != string::npos) {
                color3_num = entry.first;
                if (color3_num <= 9) multiplier = pow(10, color3_num);
                else if (color3_num == 10) multiplier = 0.1;
                else if (color3_num == 11) multiplier = 0.01;
                break;
            }
        }

        for (const auto& entry : toleranceValues) {
            if (entry.second.find(color4) != string::npos) {
                color4_num = entry.first;
                break;
            }
        }

        if (color1_num == -1 || color2_num == -1 || color3_num == -1 || color4_num == -1) {
            throw out_of_range("Invalid color input.");
        }

        // Calculate resistance
        double resistance = (color1_num * 10 + color2_num) * multiplier;
        cout << "The resistance value is " << resistance << " Ohms with tolerance " << toleranceValues.at(color4_num) << ".\n";
    } catch (const out_of_range& e) {
        cout << "Error: Invalid input.\n";
    }
}



/* 
Function:       decode5BandResistor
Input:          The color names corresponding to the five bands
Output:         Resistance decoding value
Description:    Decodes a 5-band resistor based on user input and displays the calculated resistance 
                along with the tolerance.
*/
void decode5BandResistor() {
    printColorCodeTable();
    cout << "Enter the first color: ";
    string color1 = getStringInput();
    cout << "Enter the second color: ";
    string color2 = getStringInput();
    cout << "Enter the third color: ";
    string color3 = getStringInput();
    
    printMultiplierTable();
    cout << "Enter the multiplier color: ";
    string color4 = getStringInput();
    
    printToleranceTable();
    cout << "Enter the tolerance color: ";
    string color5 = getStringInput();

    try {
        // Find the corresponding numbers for the colors
        int color1_num = -1, color2_num = -1, color3_num = -1, color4_num = -1, color5_num = -1;
        for (const auto& entry : colorNames) {
            if (entry.second == color1) color1_num = entry.first;
            if (entry.second == color2) color2_num = entry.first;
            if (entry.second == color3) color3_num = entry.first;
        }

        // Find the multiplier and tolerance values
        double multiplier;
        for (const auto& entry : multiplierValues) {
            if (entry.second.find(color4) != string::npos) {
                color4_num = entry.first;
                if (color4_num <= 9) multiplier = pow(10, color4_num);
                else if (color4_num == 10) multiplier = 0.1;
                else if (color4_num == 11) multiplier = 0.01;
                break;
            }
        }

        for (const auto& entry : toleranceValues) {
            if (entry.second.find(color5) != string::npos) {
                color5_num = entry.first;
                break;
            }
        }

        if (color1_num == -1 || color2_num == -1 || color3_num == -1 || color4_num == -1 || color5_num == -1) {
            throw out_of_range("Invalid color input.");
        }

        // Calculate resistance
        double resistance = (color1_num * 100 + color2_num * 10 + color3_num) * multiplier;
        cout << "The resistance value is " << resistance << " Ohms with tolerance " << toleranceValues.at(color5_num) << ".\n";
    } catch (const out_of_range& e) {
        cout << "Error: Invalid input.\n";
    }
}



/* 
Function:       decodeResistorColor
Input:          None
Output:         None
Description:    Main function to decode a 4-band or 5-band resistor. Allows retry or exit options 
                after each decoding attempt.
*/
void decodeResistorColor() {
    while (true) {
        cout << "Do you want to decode a 4-band or 5-band resistor? (Enter 4 or 5): ";
        int choice = getIntInput();

        if (choice == 4) {
            decode4BandResistor();
        } else if (choice == 5) {
            decode5BandResistor();
        } else {
            cout << "Invalid choice. Please enter 4 or 5.\n";
            continue;
        }

        cout << "Would you like to decode another resistor? (y/n): ";
        char retry = getCharInput();
        if (retry == 'n' || retry == 'N') {
            cout << "Exiting resistor decoder. Goodbye!\n";
            break;
        }
    }
}

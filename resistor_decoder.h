#ifndef RESISTOR_DECODER_H
#define RESISTOR_DECODER_H

#include <string>

// Function declarations
void decodeResistorColor();    // Main function to decode the resistor
void decode4BandResistor();    // Function to decode a 4-band resistor
void decode5BandResistor();    // Function to decode a 5-band resistor
void printColorCodeTable();    // Function to print the color-to-number code table
void printMultiplierTable();   // Function to print the multiplier color code table
void printToleranceTable();    // Function to print the tolerance color code table

#endif // RESISTOR_DECODER_H

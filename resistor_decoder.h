#ifndef RESISTOR_DECODER_H
#define RESISTOR_DECODER_H

#include <string>

// Function declarations for printing color, multiplier, and tolerance tables
void printColorCodeTable();
void printMultiplierTable();
void printToleranceTable();

// Function declarations for decoding resistors
void decode4BandResistor();
void decode5BandResistor();
void decodeResistorColor();

#endif // RESISTOR_DECODER_H

#ifndef OP_AMP_CALCULATOR_H
#define OP_AMP_CALCULATOR_H

#include <string>  // Include <string> to use std::string

// Operational amplifier main menu declaration
void op_amp_main_menu();                   // Declaration for the operational amplifier module main menu function

// Operational amplifier function declarations
void calculate_inverting_gain();           // Inverting amplifier gain calculation
void calculate_non_inverting_gain();       // Non-inverting amplifier gain calculation
void calculate_differential_gain();        // Differential amplifier gain calculation
void calculate_integrator_gain();          // Integrator amplifier gain calculation
void calculate_differentiator_gain();      // Differentiator amplifier gain calculation
void calculate_low_pass_filter();          // Low-pass filter cutoff frequency calculation
void calculate_high_pass_filter();         // High-pass filter cutoff frequency calculation

// Helper function declarations
double get_resistor_value(const std::string& resistor_name);   // Get resistor value with validation
double get_capacitor_value(const std::string& capacitor_name); // Get capacitor value with validation

#endif  // OP_AMP_CALCULATOR_H

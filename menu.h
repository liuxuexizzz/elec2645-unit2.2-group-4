#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <regex>



void main_menu();                           // No input, no return value. Displays the menu and gets the user's selection.
int get_user_input();                       // No explicit input, returns the menu item number selected by the user.
void select_menu_item(int input);           // Input is the menu item number selected by the user, no return value. Calls the corresponding menu function.
void print_main_menu();                     // No input, no return value. Prints the main menu.
bool is_integer(std::string num);           // Input is a string, returns a boolean indicating whether the string is an integer.
void go_back_to_main();                     // No explicit input, no return value. Prompts the user to press 'b' to return to the main menu.
void menu_item_1();                         // No input, no return value. Performs the operation for menu item 1.
void menu_item_2();                         // No input, no return value. Performs the operation for menu item 2.
void menu_item_3();                         // No input, no return value. Performs the operation for menu item 3.
void menu_item_4();                         // No input, no return value. Performs the operation for menu item 4.
void menu_item_5();                         // No input, no return value. Performs the operation for menu item 5.
void menu_item_6();                         // No input, no return value. Performs the operation for menu item 6.

#endif    // MENU_H

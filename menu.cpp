#include "menu.h"
#include "Get_user_input.h"
#include "Basic_op.h"
#include "ohms_calculator.h"
#include "resistor_decoder.h"
#include "BinaryCalculator.h"
#include "Boolean_Algebra.h"
#include "op_amp_calculator.h"

using namespace std;



/* 
Function:       print_main_menu
Input:          None
Output:         None
Description:    Prints the main menu to the console.
*/
void print_main_menu() 
{
    cout << "\n----------------- Main menu -----------------\n";
    cout << "|\t\t\t\t\t\t|\n";
    cout << "|\t1. Basic four calculation calculator\t|\n";
    cout << "|\t2. Logic gate calculator\t\t|\n";
    cout << "|\t3. Boolean expression calculator\t|\n";
    cout << "|\t4. ohms_calculator\t\t\t|\n";
    cout << "|\t5. resistor_decoder\t\t\t|\n";
    cout << "|\t6. Operational Amplifier calculator\t|\n";
    cout << "|\t7. Exit\t\t\t\t\t|\n";
    cout << "|\t\t\t\t\t\t|\n";
    cout << "------------------------------------------------\n";
}



/* 
Function:       main_menu
Input:          None
Output:         None
Description:    Displays the main menu and gets the user's input.
*/
void main_menu() 
{
    print_main_menu();
    int input = get_user_input();
    select_menu_item(input);
}



/* 
Function:       get_user_input
Input:          None
Output:         int       input       // A valid menu item number (1 to 7).
Description:    Prompts the user to select a menu item and validates the input.
*/
int get_user_input() {
    int input;
    string input_string;
    bool valid_input = false;
    int menu_items = 7;       // The maximum number of menu items (7, modify if adding functionality)

    do {
        cout << "\nSelect item: ";
        cin >> input_string;  // User input as a string
        valid_input = is_integer(input_string);
        if (valid_input == false) 
        {
            cout << "Enter an integer!\r\n";  // Prompt for integer input
        } 
        else 
        {
            input = stoi(input_string);  // Convert string to integer
            if (input >= 1 && input <= menu_items) 
            {
                valid_input = true;
            } 
            else 
            {
                cout << "Invalid menu item!\r\n";  // Prompt for a valid menu item
                valid_input = false;
            }
        }
    } 
    while (valid_input == false);

    return input;  // Return the valid integer corresponding to the menu item
}



/* 
Function:       select_menu_item
Input:          int input             // User's menu selection
Output:         None
Description:    Calls the appropriate function based on the user's menu selection.
*/
void select_menu_item(int input) {
    switch (input) {
        case 1:
            menu_item_1();
            break;
        case 2:
            menu_item_2();             
            break;
        case 3:
            menu_item_3();
            break;
        case 4:
            menu_item_4();
            break;
        case 5:
            menu_item_5();
            break;
        case 6:
            menu_item_6();
            break;
        default:
            exit(1);  // Exit the program when input is 7
            break;
    }
}



/* 
Function:       is_integer
Input:          string    num         // String representation of a number
Output:         bool      is_valid    // True if the string is a valid integer
Description:    Checks if the input string represents a valid integer.
*/
bool is_integer(string num) {
    return regex_match(num, regex("[+-]?[0-9]+"));
}



/* 
Function:       go_back_to_main
Input:          None
Output:         None
Description:    Prompts the user to input 'b' or 'B' to return to the main menu.
*/
void go_back_to_main() {
    std::string input;
    do {
        std::cout << "\nEnter 'b' or 'B' to go back to main menu: ";
        std::cin >> input;  // User input for going back
    } while (input != "b" && input != "B");
    main_menu();  // Go back to the main menu
}



/* 
Function:       menu_item_1
Input:          None
Output:         None
Description:    Executes the functionality for menu item 1 and returns to the main menu.
*/
void menu_item_1()
{
    cout << "\n>> Menu 1\r\n";
    double a, b, result;
    char op;
    basic_op status;
    // Gets the first operand
    cout << "Enter the first number: ";
    a = getDoubleInput();
    // Get operator
    cout << "Enter an operator (+, -, *, /): ";
    op = getCharInput();
    // Gets the second operand
    cout << "Enter the second number: ";
    b = getDoubleInput();
    // calculate
    status = calculate(a, b, op, result);
    // Output the result or error message based on the return value
    if (status == basic_op::SUCCESS) {
        cout << "Result: " << result << endl;
    } else {
        cout << getErrorMessage(status) << endl;
    }
    go_back_to_main();
}



/* 
Function:       menu_item_2
Input:          None
Output:         None
Description:    Executes the functionality for menu item 2 and returns to the main menu.
*/
void menu_item_2()
{
    cout << "\n>> Menu 2\n";
    string bin1, bin2;

    // Get the first binary number
    do {
        cout << "Enter the first binary number: ";
        bin1 = getStringInput();
        if (!isBinary(bin1)) {
            cout << "Invalid input! Please enter a binary number (only 0 and 1).\n";
        }
    } while (!isBinary(bin1));

    // Gets the second binary number
    do {
        cout << "Enter the second binary number: ";
        bin2 = getStringInput();
        if (!isBinary(bin2)) {
            cout << "Invalid input! Please enter a binary number (only 0 and 1).\n";
        }
    } while (!isBinary(bin2));

    // Displaying the results
    cout << "\nResults:\n";
    cout << "AND:   " << binaryAnd(bin1, bin2) << endl;
    cout << "OR:    " << binaryOr(bin1, bin2) << endl;
    cout << "NOT (first number) : " << binaryNot(bin1) << endl;
    cout << "NOT (second number): " << binaryNot(bin2) << endl;
    cout << "NAND:  " << binaryNand(bin1, bin2) << endl;
    cout << "NOR:   " << binaryNor(bin1, bin2) << endl;
    cout << "XOR:   " << binaryXor(bin1, bin2) << endl;
    cout << "XNOR:  " << binaryXnor(bin1, bin2) << endl;
    go_back_to_main();
}



/* 
Function:       menu_item_3
Input:          None
Output:         None
Description:    Executes the functionality for menu item 3 and returns to the main menu.
*/
void menu_item_3()
{
    cout << "\n>> Menu 3\n";        

    // Print the correspondence table of logic gates and symbols
    cout << "Logic Gate and Operator Symbols:\n";
    cout << "-----------------------------------\n";
    cout << "AND    : &\n";
    cout << "OR     : |\n";
    cout << "XOR    : ^\n";
    cout << "NOT    : !\n";
    cout << "NAND   : N\n";
    cout << "NOR    : R\n";
    cout << "XNOR   : X\n";
    cout << "-----------------------------------\n";
    cout << "Enter a boolean expression to check its validity: ";
    string expression = getStringInput();  

    // Check the validity of the expression
    if (isValidExpression(expression)) {
        
        // The result of evaluating a Boolean expression
        try {
            string result = evaluateExpression(expression);
            cout << "The result of the expression is: " << result << endl;
        } catch (const invalid_argument& e) {
            cout << "Error in expression evaluation: " << e.what() << endl;
        }
    } else {
        cout << "The expression is invalid. Please enter a valid expression.\n";
    }
    go_back_to_main();
}



/* 
Function:       menu_item_4
Input:          None
Output:         None
Description:    Executes the functionality for menu item 4 and returns to the main menu.
*/
void menu_item_4()
{  
    cout << "\n>> ohms_calculator\r\n";
    calculateOhmsLaw();
    go_back_to_main();
}



/* 
Function:       menu_item_5
Input:          None
Output:         None
Description:    Executes the functionality for menu item 5 and returns to the main menu.
*/
void menu_item_5()
{
    cout << "\n>> resistor_decoder\n";
    decodeResistorColor();
    go_back_to_main();    
}



/* 
Function:       menu_item_6
Input:          None
Output:         None
Description:    Executes the functionality for menu item 6 and returns to the main menu.
*/
void menu_item_6()
{
    op_amp_main_menu();
    go_back_to_main();
}




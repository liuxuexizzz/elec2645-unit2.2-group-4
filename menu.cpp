#include "menu.h"
#include "Get_user_input.h"
#include "Basic_op.h"
#include "ohms_calculator.h"
#include "resistor_decoder.h"
#include "BinaryCalculator.h"
#include "Boolean_Algebra.h"

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
    cout << "|\t2. ohms_calculator\t\t\t|\n";
    cout << "|\t3. Logic gate calculator\t\t|\n";
    cout << "|\t4. resistor_decoder\t\t\t|\n";
    cout << "|\t5. Boolean expression calculator\t|\n";
    cout << "|\t5. Operational Amplifier Calculators\t|\n";
    cout << "|\t8. Other\t\t\t\t|\n";
    cout << "|\t\t\t\t\t\t|\n";
    cout << "------------------------------------------------\n";
}



/* 
Function:       get_user_input
Input:          None
Output:         int       input       // A valid menu item number (1 to 5).
Description:    Prompts the user to select a menu item and validates the input.
*/
void main_menu() 
{
    // 无输入，无返回值。显示主菜单并获取用户选择。
    print_main_menu();
    int input = get_user_input();
    select_menu_item(input);
}



/* 
Function:       get_user_input
Input:          None
Output:         int       input       // A valid menu item number (1 to 5).
Description:    Prompts the user to select a menu item and validates the input.
*/
int get_user_input() {
    // 无显式输入，返回用户选择的菜单项编号（1 到 5）。
    int input;
    string input_string;
    bool valid_input = false;
    int menu_items = 8;       // 菜单项数上限 5（添加功能徐需修改）

    do {
        cout << "\nSelect item: ";
        cin >> input_string;  // 输入：用户输入的字符串（菜单选项）
        valid_input = is_integer(input_string);
        if (valid_input == false) 
        {
            cout << "Enter an integer!\r\n";  // 输出：提示输入整数
        } 
        else 
        {
            input = stoi(input_string);  // 将字符串转换为整数
            if (input >= 1 && input <= menu_items) 
            {
                valid_input = true;
            } 
            else 
            {
                cout << "Invalid menu item!\r\n";  // 输出：提示输入有效菜单项
                valid_input = false;
            }
        }
    } 
    while (valid_input == false);

    return input;  // 返回：有效的整数值，表示菜单选项编号
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
            menu_item_2();             //Ohms Calculator
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
        case 7:
            menu_item_7();
            break;
        case 8:
            menu_item_8();
            break;
        default:
            exit(1);  // 输入 9：退出程序
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
    // 输入：字符串 num，表示用户输入的内容。
    // 返回：布尔值，true 表示 num 是有效的整数格式。
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
        std::cin >> input;  // 输入：用户输入的字符
    } while (input != "b" && input != "B");
    main_menu();  // 调用：返回主菜单
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
    cout << "\n>> ohms_calculator\r\n";
    calculateOhmsLaw();
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
Function:       menu_item_4
Input:          None
Output:         None
Description:    Executes the functionality for menu item 4 and returns to the main menu.
*/
void menu_item_4()
{
    cout << "\n>> resistor_decoder\n";
    decodeResistorColor();
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
    cout << "\n>> Menu 5\n";        

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
        // cout << "The expression is valid.\n";
        
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



/* 
Function:       menu_item_7
Input:          None
Output:         None
Description:    Executes the functionality for menu item 7 and returns to the main menu.
*/
void menu_item_7()
{
    // 无输入，无返回值。执行菜单项 7 的操作，并返回主菜单。
    cout << "\n>> Menu 7\n";
    cout << "function performance \r\n";
    cout << "output\r\n";
    go_back_to_main();
}



/* 
Function:       menu_item_8
Input:          None
Output:         None
Description:    Executes the functionality for menu item 8 and returns to the main menu.
*/
void menu_item_8()
{
    // 无输入，无返回值。执行菜单项  的操作，并返回主菜单。
    cout << "\n>> Menu 8\n";
    cout << "function performance \r\n";
    cout << "output\r\n";
    go_back_to_main();
}




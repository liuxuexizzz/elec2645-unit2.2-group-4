#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <regex>



void main_menu();                           // 无输入，无返回值。显示菜单并获取用户选择。
int get_user_input();                       // 无显式输入，返回用户选择的菜单项编号。
void select_menu_item(int input);           // 输入为用户选择的菜单项编号，无返回值。调用相应的菜单函数。
void print_main_menu();                     // 无输入，无返回值。打印主菜单。
bool is_integer(std::string num);           // 输入为字符串，返回布尔值，表示字符串是否为整数。
void go_back_to_main();                     // 无显式输入，无返回值。提示用户按 'b' 返回主菜单。
void menu_item_1();                         // 无输入，无返回值。执行菜单项 1 的操作。
void menu_item_2();                         // 无输入，无返回值。执行菜单项 2 的操作。
void menu_item_3();                         // 无输入，无返回值。执行菜单项 3 的操作。
void menu_item_4();                         // 无输入，无返回值。执行菜单项 4 的操作。
void menu_item_5();                         // 无输入，无返回值。执行菜单项 5 的操作。




#endif    // MENU_H
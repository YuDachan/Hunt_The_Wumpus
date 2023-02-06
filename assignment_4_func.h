#ifndef ASSIGNMENT4
#define ASSIGNMENT4
#include <iostream>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include "dungeon.h"

using namespace std;
/*********************************************************************
** Function:  is_valid
** Description:  checks if the input is valid for command line
** Parameters:   char* C
** Pre-Conditions:  there are command line arguments
** Post-Conditions:  returns true or false
*********************************************************************/
bool is_valid(char* c);
/*********************************************************************
** Function: is_digit
** Description: checks if inputs are digits
** Parameters: char c
** Pre-Conditions: none
** Post-Conditions: returns true or false
*********************************************************************/
bool is_digit(char* c);
/*********************************************************************
** Function:is_digit_string
** Description: chiecks if string  input is a digit
** Parameters: string c
** Pre-Conditions:none
** Post-Conditions:returns true or false
*********************************************************************/
bool is_digit_string(string str);
/*********************************************************************
** Function: input
** Description: gets user input
** Parameters: int i, Dungeon& Dungeon
** Pre-Conditions: user input
** Post-Conditions: saves user input
*********************************************************************/
void input(int i, Dungeon& dungeon);
/*********************************************************************
** Function: input_board_size
** Description: takes in size and option for dungeon from cin
** Parameters: int size int option
** Pre-Conditions: user input
** Post-Conditions: saves user input
*********************************************************************/
void input_board_size(int& size, int& option);
/*********************************************************************
** Function: command
** Description: takes in necessary info from command line argument
** Parameters: argc argv size option
** Pre-Conditions: takes in input from command line
** Post-Conditions: stores info from command line
*********************************************************************/
void command(int argc, char** argv, int& size, int& option);
/*********************************************************************
** Function: gameplay
** Description: runs the game and its components
** Parameters: n option dungeon
** Pre-Conditions: none
** Post-Conditions: the game runs
*********************************************************************/
void gameplay(bool& n, int option, Dungeon& dungeon);
/*********************************************************************
** Function: ask_map
** Description: ask user if they want a new map or same map
** Parameters: new_map
** Pre-Conditions: user input yes or no
** Post-Conditions: stores the value of user
*********************************************************************/
void ask_map(bool& new_map);
/*********************************************************************
** Function: Play_again
** Description: asks user if they want to play the game again
** Parameters: quit new_map
** Pre-Conditions: user input to cin
** Post-Conditions: stores user input
*********************************************************************/
void play_again(bool& quit, bool& new_map);
/*********************************************************************
** Function: mod
** Description: shortens main function
** Parameters: new_map dungeon
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void mod(bool new_map, Dungeon& dungeon);

#endif // !1
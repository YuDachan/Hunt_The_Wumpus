#ifndef DUNGEON
#define DUNGEON
#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <string>
#include "room.h"
#include "wumpus.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"

class Dungeon {
private:
	std::vector<std::vector<char>> room;
	std::vector<std::vector<char>> map;
	std::vector<std::vector<Room>> items;
	static std::vector<std::vector<char>> saved_map;
	bool exit;
	int board, num_shots, saved_x, saved_y;
	Bats* bat;
	Wumpus* wumpus;
	Pit* pit;
	Gold* gold;

public:
/*********************************************************************  
** Function:  dungeon
** Description:  initialize all variables and determines vector sizes
** Parameters:   int size
** Pre-Conditions:  none
** Post-Conditions:  all variables in class is initialized
*********************************************************************/
	Dungeon(int size);
/*********************************************************************  
** Function:  location
** Description:  set the player at a random location
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  a * is place in a random coordinate and is saved
*********************************************************************/
	void location();
/*********************************************************************  
** Function:  set_events
** Description:  puts two bat and pit events, one wumpus, and one 
* gold event in the game and randomizes the placements
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  all events are placed
*********************************************************************/
	void set_events();
/*********************************************************************  
** Function:  set_events2
** Description:  initializes the events for each room
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  all rooms in room vector has events
*********************************************************************/
	void set_events2();
/*********************************************************************  
** Function:  save_map
** Description:  saves all placements of player and events
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  map is saved
*********************************************************************/
	void save_map();
/*********************************************************************  
** Function:  valid_move
** Description:  checks if wasd movement is in vector size
** Parameters:   move
** Pre-Conditions:  none
** Post-Conditions:  returns true or false depending 
*********************************************************************/
	bool valid_move(char move);
/*********************************************************************  
** Function:  places items
** Description:  copies the placements of items onto player map
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  player can now see all event placements
*********************************************************************/
	void place_items();
/*********************************************************************  
** Function:  movement
** Description:  moves the player across the board
** Parameters:   move
** Pre-Conditions:  none
** Post-Conditions:  position of player is changed
*********************************************************************/
	void movement(char move);
/*********************************************************************  
** Function:  print_room
** Description:  room is displayed
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  room is displayed along with player
*********************************************************************/
	void print_room();
/*********************************************************************  
** Function:  print_no_room
** Description:  room is displayed
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  room is displayed along with player
*********************************************************************/
	void print_no_room();
/*********************************************************************  
** Function:  perceptions
** Description:  determines if the player is next to an event tile
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  calls a class function
*********************************************************************/
	void perceptions();
/*********************************************************************  
** Function:  encounters
** Description:  determines if player lands on an event tile
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  another class type function is called
*********************************************************************/
	void encounters();
/*********************************************************************  
** Function:  check_gold
** Description:  checks if the player has gotten the treasure
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  if player has gold msg is displayed
*********************************************************************/
	void check_gold();
/*********************************************************************  
** Function:  death_status
** Description:  checks if player has died
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  if player dies from either pit or wumpus returns
* true
*********************************************************************/
	bool death_status();
/*********************************************************************  
** Function:  get_exit
** Description:  returns exit
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  return exit
*********************************************************************/
	bool get_exit();
/*********************************************************************  
** Function:  bats_randomizer
** Description:  places player on a random tile
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  player is placed on a random tile
*********************************************************************/
	void bats_randomizer();
/*********************************************************************  
** Function:  wumpus_schmoovin
** Description:  75 percent chance wumpus moves if arrows miss
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  moves wumpus to a random tile
*********************************************************************/
	void wumpus_schmoovin();
/*********************************************************************  
** Function:  excute_wumpus
** Description:  removes wumpus from the board
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  wumpus icon and event is removed from the game
*********************************************************************/
	void execute_wumpus();
/*********************************************************************  
** Function:  shot
** Description:  shoots an arrow through three tiles at a certain 
direction
** Parameters:   char c
** Pre-Conditions:  none
** Post-Conditions:  checks if wumpus is present at shot location
*********************************************************************/
	void shoot(char c);
/*********************************************************************  
** Function:  gets_shots
** Description:  returns number of arrows
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  returns number of arrows
*********************************************************************/
	int get_shots();
/*********************************************************************  
** Function:  dungeon_reset
** Description:  reset the dungeon to original state
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  map is return to created map
*********************************************************************/
	void dungeon_reset();
/*********************************************************************  
** Function: ~Dungeon
** Description:  frees all memory
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  memory is freed
*********************************************************************/
	~Dungeon();

};

#endif // !dungeon

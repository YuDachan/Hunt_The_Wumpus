#ifndef ROOM
#define ROOM
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cstring>
#include "event.h"
#include "wumpus.h"
#include "gold.h"
#include "pit.h"
#include "bats.h"


class Room {
private:
	Event *events;
public:

/********************************************************************* 
** Function:room
** Description: constructor
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions:  set events pointer to null
*********************************************************************/
	Room();

/********************************************************************* 
** Function: msg
** Description: performs function from other classes
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions:  a function from a set of classes is performed
*********************************************************************/
	void msg();

/********************************************************************* 
** Function: set_event
** Description: make this event pointer point toward a specific class
** Parameters:  event pointer
** Pre-Conditions: none
** Post-Conditions:  event pointer is pointing to a specific class
*********************************************************************/
	void set_event(Event* item);

/********************************************************************* 
** Function: set_encounter
** Description: points to a function from a different class
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions:  a function from a specific class is run
*********************************************************************/
	void set_encounter();

/********************************************************************* 
** Function: set_null
** Description: set the event pointer to null
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions:  pointer is set to null
*********************************************************************/
	void set_null();

};

#endif // !ROOM

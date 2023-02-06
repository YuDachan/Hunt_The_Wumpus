#ifndef WUMPUS
#define WUMPUS
#include <iostream>
#include "event.h"

class Wumpus : public Event {
private:
	bool death;
public:
/*********************************************************************
** Function:wumpus
** Description: default constructor 
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: set death to false
*********************************************************************/
	Wumpus();
/*********************************************************************
** Function: display_msg
** Description: displays the messege for when the player is next to 
* wumpus
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: messege is displayed
*********************************************************************/
	void display_msg();
/*********************************************************************
** Function: encounter
** Description: changes death to true and displays messege of
* interaction with wumpus
** Parameters: none
** Pre-Conditions: player steps on wumpus square
** Post-Conditions: message is displayed
*********************************************************************/
	void encounter();
/*********************************************************************
** Function: get_death
** Description: return if death is true
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns death
*********************************************************************/
	bool get_death();
};

#endif // !1

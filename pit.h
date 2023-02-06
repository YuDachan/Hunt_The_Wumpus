#ifndef PIT
#define PIT
#include <iostream>
#include "event.h"


class Pit : public Event {
private:
	bool death;
public:

/*********************************************************************  
** Function:  pit
** Description:  constructor
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  set death to false
*********************************************************************/
	Pit();
/*********************************************************************  
** Function:  display_msg
** Description:  a msg is displayed when player is next to pit tile
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  msg is displayed
*********************************************************************/
	void display_msg();
/*********************************************************************  
** Function:  encounter
** Description:  a message is displayed that the player fell and 
* sets death to true
** Parameters: none  
** Pre-Conditions: none 
** Post-Conditions: death is set to true and msg is displayed 
*********************************************************************/
	void encounter();
/*********************************************************************  
** Function:  deaths
** Description:  returns death
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  returns death
*********************************************************************/
	bool deaths();
};
#endif // !PIT

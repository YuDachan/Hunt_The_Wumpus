#ifndef BATS
#define BATS
#include <iostream>
#include "event.h"

class Bats : public Event {
private:
	bool landed_bat;
public:
/*********************************************************************  
** Function:  Bats
** Description:  contructor
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  initialize variables
*********************************************************************/
	Bats();
/*********************************************************************
** Function:display_msg
** Description: displays the message when player is next to bat tile
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: messege is displayed
*********************************************************************/
	void display_msg();
/*********************************************************************  
** Function:  encounter
** Description:  sets landed_bat to tru and tells user that he has
* landed on bat tile
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  landed_bat is set true
*********************************************************************/
	void encounter();
/*********************************************************************  
** Function:  original_position
** Description:  makes landed_bats false
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  landed_bat is now false
*********************************************************************/
	void original_position();
/*********************************************************************  
** Function:  get_bat
** Description:  return bats
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  return bat
*********************************************************************/
	bool get_bat();
};
#endif // !BATS

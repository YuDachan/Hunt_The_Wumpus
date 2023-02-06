#ifndef GOLD
#define GOLD
#include <iostream>
#include "event.h"

class Gold : public Event {
private:
	bool grabbed;
public:

/*********************************************************************  
** Function:  gold
** Description:  constructor
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  grabbed is set to false
*********************************************************************/
	Gold();
/*********************************************************************  
** Function:  displayed_msg
** Description:  displays messeage when player is next to gold tile
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  message is displayed
*********************************************************************/
	void display_msg();
/*********************************************************************  
** Function:  encounter
** Description:  message displays when player hits gold icon and sets
* grab to true
** Parameters: none   
** Pre-Conditions:  none
** Post-Conditions:  grabbed is set to true and message is displayed
*********************************************************************/
	void encounter();
/*********************************************************************  
** Function:  get_grab
** Description:  returns grabbed
** Parameters:   none
** Pre-Conditions:  none
** Post-Conditions:  returns grabbed
*********************************************************************/
	bool get_grab();
};
#endif // !GOLD

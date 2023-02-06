#ifndef EVENTS
#define EVENTS
#include <iostream>

class Event {
public:

	virtual void display_msg() = 0;

	virtual void encounter() = 0;

	virtual ~Event();
};
#endif // !event

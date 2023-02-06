#include "room.h"

using namespace std;

Room::Room() {
	events = NULL;
}

void Room::msg() {
	events->display_msg();
}

void Room::set_event(Event* item) {
	events = item;
}

void Room::set_encounter() {
	events->encounter();
}

void Room::set_null() {
	events = NULL;
}
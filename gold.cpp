#include "gold.h"


using namespace std;

Gold::Gold() {
	grabbed = false;
}

void Gold::display_msg() {
	cout << "you see a glimmer nearby" << endl;
}

void Gold::encounter() {
	cout << "you have picked up the treasure!" << endl;
	grabbed = true;
}

bool Gold::get_grab() {
	return grabbed;
}
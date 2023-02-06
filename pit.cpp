#include "pit.h"

using namespace std;

Pit::Pit() {
	death = false;
}

void Pit::display_msg() {
	cout << "you feel a cool breeze swirling by" << endl;
}

void Pit::encounter() {
	cout << "you fell to your death" << endl << endl;
	death = true;
}

bool Pit::deaths() {
	return death;
}
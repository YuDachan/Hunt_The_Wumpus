#include "wumpus.h"

using namespace std;

Wumpus::Wumpus() {
	death = false;
}

void Wumpus::display_msg() {
	cout << "you smell something smelly, like super smelly" << endl;
}

void Wumpus::encounter() {
	cout << "you died from wumpus sitting on you with his big stinky cheecks" << endl << endl;
	death = true;
}

bool Wumpus::get_death() {
	return death;
}
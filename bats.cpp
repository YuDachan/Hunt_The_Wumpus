#include "bats.h"

using namespace std;

Bats::Bats() {
	landed_bat = false;
}

void Bats::display_msg() {
	cout << "you hear wings flapping" << endl;
}

void Bats::encounter() {
	cout << "you have moved to a different space" << endl;
	landed_bat = true;
}

void Bats::original_position() {
	landed_bat = false;
}

bool Bats::get_bat() {
	return landed_bat;
}
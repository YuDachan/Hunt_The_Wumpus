#include "assignment_4_func.h"

using namespace std;

bool is_valid(char* c) {
	if (strlen(c) > 2) {
		return false;
	}
	else if ((c[0] == ' ')) {
		if (c[1] == 'd' || c[1] == 's' || c[1] == 'a' || c[1] == 'w') {
			return true;
		}
		else {
			return false;
		}

	}
	else if ((c[0] == 'd' || c[0] == 's' || c[0] == 'a' || c[0] == 'w') && strlen(c) == 1) {
		return true;
	}
	else
		return false;
}

bool is_digit(char* c) {
	for (int i = 0; i < strlen(c); i++) {
		if (isdigit(c[i])) {

		}
		else {
			return false;
		}
	}

	return true;
}

bool is_digit_string(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (isdigit(str[i])) {

		}
		else {
			return false;
		}
	}
	return true;
}

void input(int i, Dungeon& dungeon) {
	char c[1024];

	do {
		cout << "Move with wasd" << endl;
		cout << "Shoot with ' 'w, ' 'a, ' 's, ' 'd " << endl;
		cin.getline(c, 1023);
		if (is_valid(c)) {

			if (dungeon.valid_move(c[0]) && strlen(c) == 1) {
				break;
			}
			else if (c[0] == ' ' && (dungeon.valid_move(c[1]) == true) && dungeon.get_shots() > 0) {
				break;
			}
		}
		cout << "poor input" << endl << endl;
		cin.clear();
		c[0] = '0';
	} while (c[0] != 'd' && c[0] != 's' && c[0] != 'a' && c[0] != 'w');

	if (strlen(c) == 1) {
		dungeon.movement(c[0]);
	}
	else if (strlen(c) == 2) {
		dungeon.shoot(c[1]);
	}
}

void input_board_size(int& size, int& option) {
	string str;
	bool n = true;
	do {
		cout << "enter the board size" << endl;
		getline(cin, str);
		if (is_digit_string(str)) {
			size = stoi(str);
			if (size >= 4) {
				break;
			}
		}
		cout << "poor input" << endl << endl;
	} while (n == true);
	cout << endl;
	do {
		cout << "Would you like to see the board?" << endl;
		cout << "[1]Yes [2]No" << endl;
		getline(cin, str);
		if (is_digit_string(str)) {
			option = stoi(str);
			if (option == 1 || option == 2) {
				break;
			}
		}
		cout << "poor input" << endl << endl;
	} while (n == true);
	cout << endl << endl;
}

void command(int argc, char** argv, int& size, int& option) {

	if (argc == 3) {
		if (is_digit(argv[1]) && is_digit(argv[2])) {
			size = atoi(argv[1]);
			option = atoi(argv[2]);
			if (size < 4 || option != 1 && option != 2) {
				option = 0;
				size = 0;
			}
			else {
			}
		}
	}
	else {
		input_board_size(size, option);
	}
	if (option == 0 && size == 0) {
		input_board_size(size, option);
	}
}

void gameplay(bool& n, int option, Dungeon& dungeon) {
	dungeon.print_room();
	cout << endl;
	dungeon.perceptions();
	input(1, dungeon);
	if (option == 1) {
		dungeon.place_items();
	}
	dungeon.encounters();

	dungeon.bats_randomizer();

	dungeon.encounters();
	dungeon.check_gold();
	cout << endl;
	if (dungeon.get_exit() == true) {
		n = true;
	}
	else if (dungeon.death_status() == true) {
		n = true;
	}
}

void ask_map(bool& new_map) {
	char c[1024];
	int x = 1;

	do {
		cout << "[1]New Map [2]Same Map" << endl;
		cin.getline(c, 1023);
		if (strlen(c) == 1 && (c[0] == '1' || c[0] == '2')) {
			if (c[0] == '1') {
				new_map = true;
			}
			else {
				new_map = false;
			}
			break;
		}
		cout << "poor input" << endl;
	} while (x == 1);
}

void play_again(bool& quit, bool& new_map) {
	char c[1024];

	do {
		cout << "would you like to play again?" << endl;
		cout << "[1]Quit [2]New Game" << endl;
		cin.getline(c, 1023);
		if (strlen(c) == 1 && (c[0] == '1' || c[0] == '2')) {
			if (c[0] == '1') {
				quit = true;
				break;
			}
			else {
				ask_map(new_map);
				break;
			}

		}
		cout << "poor input" << endl;
	} while (quit != true);



}

void mod(bool new_map, Dungeon& dungeon) {
	if (new_map == true) {
		dungeon.location();
		dungeon.set_events();
		dungeon.set_events2();
		dungeon.save_map();

	}
	else if (new_map == false) {
		dungeon.dungeon_reset();
		dungeon.set_events2();
	}
}
#include "dungeon.h"

using namespace std;

Dungeon::Dungeon(int size) {

	room.resize(size);
	items.resize(size);
	map.resize(size);
	saved_map.resize(size);
	board = size;

	bat = new Bats();
	wumpus = new Wumpus();
	pit = new Pit();
	gold = new Gold();

	for (int i = 0; i < size; i++) {
		room[i].resize(size);
		items[i].resize(size);
		map[i].resize(size);
		saved_map[i].resize(size);
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			map[i][j] = ' ';
			room[i][j] = ' ';
		}
	}

	exit = false;
	num_shots = 3;

}

void Dungeon::location() {
	int x = rand() % board;
	int y = rand() % board;

	room[x][y] = '*';
	map[x][y] = '^';

	saved_x = x;
	saved_y = y;
}

void Dungeon::set_events() {
	int swumpus = 1;
	int sbats = 2;
	int spits = 2;
	int sgold = 1;
	int no = 0;
	int z, y, x;

	for (int i = 0; i < 6; i++) {
		do {
			x = rand() % board;
			y = rand() % board;
		} while (map[x][y] != ' ');
		do {
			z = (rand() % 4) + 1;
			if ((z == 1) && (swumpus != 0)) {
				map[x][y] = 'W';
				swumpus--;
				break;
			}
			else if ((z == 2) && (sgold != 0)) {
				map[x][y] = 'G';
				sgold--;
				break;
			}
			else if ((z == 3) && (sbats != 0)) {
				map[x][y] = 'B';
				sbats--;
				break;
			}
			else if ((z == 4) && (spits != 0)) {
				map[x][y] = 'P';
				spits--;
				break;
			}
		} while (no != 1);
	}

	/*******************************************************
	* I do not think I can split this up into multiple
	* functions nor do I think I can shorten this anymore.
	*******************************************************/
}

void Dungeon::set_events2() {
	for (int x = 0; x < board; x++) {
		for (int y = 0; y < board; y++) {

			if (map[x][y] == 'W') {
				items[x][y].set_event(wumpus);
			}

			if (map[x][y] == 'G') {
				items[x][y].set_event(gold);
			}

			if (map[x][y] == 'B') {
				items[x][y].set_event(bat);
			}

			if (map[x][y] == 'P') {
				items[x][y].set_event(pit);
			}
		}
	}
}

void Dungeon::save_map() {
	for (int i = 0; i < board; i++) {
		for (int j = 0; j < board; j++) {
			saved_map[i][j] = map[i][j];
		}
	}
}

bool Dungeon::valid_move(char move) {
	for (int i = 0; i < board; i++) {

		for (int j = 0; j < board; j++) {
			if ((move == 'd') && (room[i][j] == '*')) {
				if (j + 1 > board - 1) {
					return false;
				}
			}
			else if ((move == 's') && (room[i][j] == '*')) {
				if (i + 1 > board - 1) {
					return false;
				}
			}
			else if (move == 'a' && (room[i][j] == '*')) {
				if (j - 1 < 0) {
					return false;
				}
			}
			else if (move == 'w' && (room[i][j] == '*')) {
				if (i - 1 < 0) {
					return false;
				}
			}
		}
	}

	return true;
}

void Dungeon::place_items() {
	for (int i = 0; i < board; i++) {
		for (int j = 0; j < board; j++) {
			if (room[i][j] != '*') {
				room[i][j] = map[i][j];
			}
		}
	}
}

void Dungeon::movement(char move) {

	bool x = false;

	for (int i = 0; i < board; i++) {
		for (int j = 0; j < board; j++) {
			if ((move == 'd') && (room[i][j] == '*')) {
				room[i][j] = ' ';
				room[i][j + 1] = '*';
				x = true;
				break;
			}
			else if ((move == 's') && (room[i][j] == '*')) {
				room[i][j] = ' ';
				room[i + 1][j] = '*';
				x = true;
			}
			else if (move == 'a' && (room[i][j] == '*')) {
				room[i][j] = ' ';
				room[i][j - 1] = '*';
				x = true;
			}
			else if (move == 'w' && (room[i][j] == '*')) {
				room[i][j] = ' ';
				room[i - 1][j] = '*';
				x = true;
			}
		}
		if (x == true) {
			break;
		}

	}

	/******************************************************
	* I could not shorten this anymore than I already have
	*******************************************************/
}

void Dungeon::print_room() {

	cout << endl << endl;
	cout << "arrows left: " << num_shots << endl;
	for (int i = 0; i < board; i++) {

		cout << "+";
		for (int j = 0; j < board; j++) {
			cout << "---+";
		}
		cout << endl;
		cout << "| ";
		for (int j = 0; j < board; j++) {
			cout << room[i][j];
			cout << " | ";
		}
		cout << endl;
	}
	cout << "+";
	for (int j = 0; j < board; j++) {
		cout << "---+";
	}
	cout << endl << endl;
}

void Dungeon::print_no_room() {

	cout << endl << endl;
	for (int i = 0; i < board; i++) {

		cout << "+";
		for (int j = 0; j < board; j++) {
			cout << "---+";
		}
		cout << endl;
		cout << "| ";
		for (int j = 0; j < board; j++) {
			cout << room[i][j];
			cout << " | ";
		}
		cout << endl;
	}
	cout << "+";
	for (int j = 0; j < board; j++) {
		cout << "---+";
	}
	cout << endl << endl;
}

void Dungeon::perceptions() {
	for (int i = 0; i < board; i++) {
		for (int j = 0; j < board; j++) {
			if (room[i][j] == '*') {
				if (((j + 1) < board) && map[i][j + 1] != ' ' && map[i][j + 1] != '^') {
					items[i][j + 1].msg();
				}
				if ((j - 1 >= 0) && map[i][j - 1] != ' ' && map[i][j - 1] != '^') {
					items[i][j - 1].msg();
				}
				if (((i + 1) < board) && map[i + 1][j] != ' ' && map[i + 1][j] != '^') {
					items[i + 1][j].msg();
				}
				if ((i - 1) >= 0 && (map[i - 1][j] != ' ' && map[i - 1][j] != '^')) {
					items[i - 1][j].msg();
				}
			}
		}
	}
}

void Dungeon::encounters() {
	for (int i = 0; i < board; i++) {
		for (int j = 0; j < board; j++) {
			if (room[i][j] == '*' && map[i][j] == '^') {
				if (gold->get_grab() == true) {
					exit = true;
				}
			}
			else if (room[i][j] == '*' && map[i][j] != ' ') {
				items[i][j].set_encounter();
			}
		}
	}
}

void Dungeon::check_gold() {
	if (gold->get_grab() == true) {
		cout << "I have the treasure!" << endl;
	}
}

bool Dungeon::death_status() {
	if (wumpus->get_death() == true || pit->deaths() == true) {
		return true;
	}
	else {
		return false;
	}
}

bool Dungeon::get_exit() {
	return exit;
}

void Dungeon::bats_randomizer() {
	if (bat->get_bat() == true) {
		int x = rand() % board;
		int y = rand() % board;

		for (int i = 0; i < board; i++) {
			for (int j = 0; j < board; j++) {
				if (room[i][j] == '*') {
					room[i][j] = ' ';
				}
			}
		}

		room[x][y] = '*';

		place_items();

		bat->original_position();
	}
}

void Dungeon::wumpus_schmoovin() {
	int x = rand() % 4;
	int y, z;

	if (x > 0) {
		do {
			y = rand() % board;
			z = rand() % board;
		} while (map[y][z] != ' ' && room[y][z] != '*');

		for (int i = 0; i < board; i++) {
			for (int j = 0; j < board; j++) {
				if (map[i][j] == 'W') {
					map[i][j] = ' ';
					items[i][j].set_null();

				}
			}
		}

		map[y][z] = 'W';
		items[y][z].set_event(wumpus);

	}
}

void Dungeon::execute_wumpus() {
	for (int i = 0; i < board; i++) {
		for (int j = 0; j < board; j++) {
			if (map[i][j] == 'W') {
				map[i][j] = ' ';
				items[i][j].set_null();
				cout << "you hear a loud cry" << endl;
			}
		}
	}
}

void Dungeon::shoot(char c) {

	for (int i = 0; i < board; i++) {
		for (int j = 0; j < board; j++) {
			if (room[i][j] == '*') {

				if (c == 'w') {
					if (map[i - 1][j] == 'W' ||
						((i - 2) >= 0 && map[i - 2][j] == 'W') ||
						((i - 3) >= 0 && map[i - 3][j] == 'W'))

					{
						execute_wumpus();
					}
					else {
						wumpus_schmoovin();
					}

				}

				else if (c == 's') {
					if (map[i + 1][j] == 'W' ||
						(board - 1 > (i + 2) && map[i + 2][j] == 'W') ||
						(board - 1 > (i + 2) && map[i + 3][j] == 'W'))
					{
						execute_wumpus();
					}
					else {
						wumpus_schmoovin();
					}

				}

				else if (c == 'd') {
					if (map[i][j + 1] == 'W' ||
						(board - 1 > (j + 2) && map[i][j + 2] == 'W') ||
						(board - 1 > (j + 3) && map[i][j + 3] == 'W'))
					{
						execute_wumpus();
					}
					else {
						wumpus_schmoovin();
					}

				}

				if (c == 'a') {
					if (map[i][j - 1] == 'W' ||
						(0 <= (j - 2) && map[i][j - 2] == 'W') ||
						(0 <= (j - 3) && map[i][j - 3] == 'W'))
					{
						execute_wumpus();
					}
					else {
						wumpus_schmoovin();
					}
				}
			}
		}
	}

	num_shots--;

	/**********************************
	* I tried to shorten this function
	* as much as possible, but I could
	* not figure out another way.
	***********************************/
}

int Dungeon::get_shots() {
	return num_shots;
}

void Dungeon::dungeon_reset() {
	for (int i = 0; i < board; i++) {
		for (int j = 0; j < board; j++) {
			map[i][j] = saved_map[i][j];
			items[i][j].set_null();
			if (room[i][j] == '*') {
				room[i][j] = ' ';
			}
		}
	}
	room[saved_x][saved_y] = '*';
}

Dungeon::~Dungeon() {
	for (int i = 0; i < board; i++) {
		items[i].clear();
		map[i].clear();
		room[i].clear();
	}
	items.clear();
	map.clear();
	room.clear();

	delete bat;
	delete pit;
	delete gold;
	delete wumpus;
}

std::vector<std::vector<char>> Dungeon::saved_map;
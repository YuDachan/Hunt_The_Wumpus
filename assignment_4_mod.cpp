/******************************************************
** Program: Assignment_4_mod.cpp
** Author: Dachan Yu
** Date: 05/23/2021
** Description: a modified game of hunt the wumpus
** Input: prompted user inputs
** Output: displayed messages
******************************************************/
#include "assignment_4_func.h"

using namespace std;



int main(int argc, char** argv) {
	srand(time(NULL));
	bool n = false, quit = false, new_map = true;
	int size = 0, option = 0, count = 0;
	char x[1023];

	do {

		if (count == 0) {
			command(argc, argv, size, option);
		}
		else if (count > 0 && new_map == true) {
			input_board_size(size, option);
		}
		Dungeon dungeon(size);
		mod(new_map, dungeon);

		if (option == 1) {
			dungeon.place_items();
		}

		while (n == false) {
			gameplay(n, option, dungeon);
		}
		dungeon.print_room();

		if (dungeon.get_exit() == true) {
			cout << "You Win!" << endl;
		}
		cout << "game over" << endl;

		play_again(quit, new_map);

		n = false;

		count++;

	} while (quit == false);

	return 0;
}
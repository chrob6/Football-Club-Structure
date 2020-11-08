#include <iostream>
#include "Football_player.h"

using namespace std;

class Board {

private:
	string position;
	string name;
	string surname;

public:

	Board(string _position, string _name, string _surname) {
		position = _position;
		name = _name;
		surname = _surname;
	}
	void dismissal(Football_player player);

	void newplayer(Candidate candidate);

	void bonus();
};



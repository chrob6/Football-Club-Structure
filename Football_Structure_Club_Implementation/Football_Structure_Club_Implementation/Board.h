#include <iostream>
#include "Football_player.h"

using namespace std;

class Board {

private:
	int login = 1000;
	//string name;
	//string surname;

public:

	/*Board(string _login, string _name, string _surname) {
		login = _login;
		//name = _name;
		//surname = _surname;
	}*/
	void dismissal(Football_player player);

	void newplayer(Candidate candidate);

	void bonus();
};



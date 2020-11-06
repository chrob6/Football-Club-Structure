#ifndef BOARD_H
#define BOARD_H

class Board {

private:
	string position;
	string name;
	string surname;

public:
	void dismissal(Football_player player);

	void newPlayer(Candidate candidate);

	void bonus();
};

#endif

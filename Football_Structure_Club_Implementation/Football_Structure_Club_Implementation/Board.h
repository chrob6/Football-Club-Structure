#include <iostream>
#include "Football_player.h"
#include <vector>
#include "Coach.h"
#include "Candidate.h"

using namespace std;

class Board {

private:
	int login = 1000;

public:
	void login_board(vector<Candidate> &base_candidates, vector<Football_player> &base_players, Coach &coach, vector<Timetable> &base_timetable_train);

	void dismissal(Football_player player);

	void newplayer(Candidate candidate);

	void bonus();
};



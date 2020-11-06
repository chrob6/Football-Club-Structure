#ifndef FOOTBALL_PLAYER_H
#define FOOTBALL_PLAYER_H

#include <string>
#include "Candidate.h"

using namespace std;

class Football_player : Candidate {

private:
	int number;
	float salary;
	int goals;
	int minutes_played;

public:
	void progressCheck(int goals, int minutes);

	int Getnumber();

	int GetStats();

	void InsertStats(int goals, int minutes);

	void updateSalary(float bonus);
};

#endif

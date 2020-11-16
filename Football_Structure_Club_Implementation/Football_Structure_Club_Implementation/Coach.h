#ifndef COACH_H
#define COACH_H

#include <string>
#include <vector>
#include "Timetable.h"
#include "Football_player.h"

using namespace std;

class Coach {

private:
	int login = 100;
 	string name = "Marcin";
	string surname = "Nowak";
	float salary = 10000;

public:
	void updateSalary(float bonus);
	void login_coach(vector<Football_player> &base_players, vector<Timetable> &timetable_phy, vector<Timetable> &timetable_train);
};




#endif

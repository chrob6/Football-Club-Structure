#ifndef FOOTBALL_PLAYER_H
#define FOOTBALL_PLAYER_H

#include <string>
#include <iostream>
#include "Candidate.h"
#include <vector>
#include "Timetable.h"

using namespace std;

class Football_player : public Candidate {

private:
	int number;
	float salary;
	int goals;
	int minutes_played;

public:

	Football_player(int _number, int _salary):Candidate(age,name,surname,position){
		salary = _salary;
		goals = 0;
		minutes_played = 0;
	}

	Football_player(int _number, int _salary, int _age, string _name, string _surname, string _position) {
		number = _number;
		age = _age;
		name = _name;
		surname = _surname;
		position = _position;
		salary = _salary;
		goals = 0;
		minutes_played = 0;
	}

	//void progressCheck(int goals, int minutes);
	void progressCheck();

	int Getnumber();

	void SetGoals(int _goals);

	void SetMin(int _min);

	int GetStats();

	void InsertStats(int goals, int minutes);

	void updateSalary(float bonus);

	void login_player(vector<Timetable> &base_timetable_phy, vector<Timetable> &base_timetable_train);
};

#endif

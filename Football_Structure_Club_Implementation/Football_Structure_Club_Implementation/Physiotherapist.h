#ifndef PHYSIOTHERAPIST_H
#define PHYSIOTHERAPIST_H

#include <string>
#include <vector>
#include "Timetable.h"

using namespace std;

class Physiotherapist {

private:
	string name = "Ziutek";
	string surname = "Makaroni";
	int login = 111;

public:
	void login_phy(vector<Timetable> &timetable_phy);
};

#endif

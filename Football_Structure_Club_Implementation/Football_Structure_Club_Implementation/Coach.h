#ifndef COACH_H
#define COACH_H

#include <string>

using namespace std;

class Coach {

private:
	string name = "Marcin";
	string surname = "Nowak";
	float salary = 10000;

public:
	void updateSalary(float bonus);
};

#endif

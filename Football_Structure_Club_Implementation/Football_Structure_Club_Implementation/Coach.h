#ifndef COACH_H
#define COACH_H

#include <string>

using namespace std;

class Coach {

private:
	string name;
	string surname;
	float salary;

public:
	void updateSalary(float bonus);
};

#endif

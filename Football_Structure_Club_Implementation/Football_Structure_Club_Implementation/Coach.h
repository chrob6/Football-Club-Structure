#ifndef COACH_H
#define COACH_H

#include <string>

using namespace std;

class Coach {

private:
	int login = 100;
 	string name = "Marcin";
	string surname = "Nowak";
	float salary = 10000;

public:
	void updateSalary(float bonus);
	void login_coach();
};




#endif

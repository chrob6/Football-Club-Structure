#ifndef TIMETABLE_H
#define TIMETABLE_H
#include <string>

using namespace std;

class Timetable {

private:
	string day;
	int lasting_minutes;
	double start_time;

public:
	void update();

	void show();
};

#endif

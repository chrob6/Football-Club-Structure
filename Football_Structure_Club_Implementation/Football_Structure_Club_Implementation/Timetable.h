#ifndef TIMETABLE_H
#define TIMETABLE_H
#include <string>
#include <iostream>


using namespace std;

class Timetable {

private:
	string day;
	int lasting_minutes;
	string start_time;

public:
	Timetable(string _day, int _lasting_minutes, string _start_time) {
		day = _day;
		lasting_minutes = _lasting_minutes;
		start_time = _start_time;
	}

	void update();

	void show();

};

#endif

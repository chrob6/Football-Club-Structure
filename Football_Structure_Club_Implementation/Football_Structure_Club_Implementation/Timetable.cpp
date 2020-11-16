#include "Timetable.h"

void Timetable::update(int min, string h) {
	lasting_minutes = min;
	start_time = h;

}

void Timetable::show() {
	cout << "Day: " << day;
	cout << "    Time: " << lasting_minutes;
	cout << "    Start Time: " << start_time << endl;
}

string Timetable::GetDay() {
	return day;
}

string Timetable::GetTime() {
	return start_time;
}

void Timetable::update(int min, string h, string _day) {
	lasting_minutes = min;
	start_time = h;
	day = _day;
}
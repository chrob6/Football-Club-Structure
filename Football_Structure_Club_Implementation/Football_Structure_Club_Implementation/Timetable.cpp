#include "Timetable.h"

void Timetable::update( string h) {
	//lasting_minutes = min;
	start_time = h;

}

void Timetable::show() {
	cout << "Day: " << day;
	cout << "    Time: " << GetLastingMinutes()->getMinutes();
	cout << "    Start Time: " << start_time << endl;
}

string Timetable::GetDay() {
	return day;
}

string Timetable::GetTime() {
	return start_time;
}

void Timetable::update(string h, string _day) {
	//lasting_minutes = min;
	start_time = h;
	day = _day;
}
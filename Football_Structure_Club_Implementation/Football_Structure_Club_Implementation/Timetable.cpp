#include "Timetable.h"


void Timetable::update( string h) {
	//lasting_minutes = min;
	start_time = h;
	this->notifyObservators();
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
	this->notifyObservators();
}

void Timetable::notifyObservators() {
	list<Observer*>::iterator iter;
	for (iter = observers.begin(); iter != observers.end(); iter++)
		(*iter)->update();

}

void Timetable::addObservator(Observer &object) {
	observers.push_back(&object);
}

void Timetable::removeObservator(Observer &object) {
	observers.remove(&object);
}
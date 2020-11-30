#ifndef TIMETABLE_H
#define TIMETABLE_H
#include <string>
#include <iostream>

using namespace std;

class LastingTime {
protected:
	int minutes;
	string name;
public:
	LastingTime(int min, string n) : minutes(min), name(n) {};
	string getName() { return name; }
	int getMinutes() { return minutes; }
};

class PhyMinutes : public LastingTime {
public:
	PhyMinutes() :LastingTime(45, "Phy") {}
};

class TrainMinutes : public LastingTime {
public:
	TrainMinutes() :LastingTime(90, "Train") {}
};


class Timetable {

private :
	string name;
	string day;
	string start_time;
	LastingTime* lasting_minutes;
	

public:
	Timetable(string n) :name(n) {
		
	}

	/*Timetable(string _day, int _lasting_minutes, string _start_time) {
		day = _day;
		start_time = _start_time;
	}*/
	

	void setMinutes(LastingTime* l) { lasting_minutes = l; }

	void setDay(string d) { day = d; }

	void setStartTime(string st) { start_time = st; }


	string GetDay();

	string GetTime();

	void update(string h);
	void update(string h, string _day);

	void show();

	LastingTime* GetLastingMinutes() { return lasting_minutes; }

};

#endif
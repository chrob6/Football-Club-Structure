#include <iostream>
#include "Timetable.h"


using namespace std;

class TimetableFactory {
private:
	Timetable *timetable;

protected:
	virtual LastingTime* createMinutes() = 0;

public: 
	virtual Timetable* createTimetable(string day, string start_time) = 0;

};

class PhyTimetableFactory : public TimetableFactory {
	LastingTime* createMinutes() {
		return new PhyMinutes();
	}

	Timetable * createTimetable(string day, string start_time) {
		Timetable *timetable = new Timetable("Phy");
		timetable->setMinutes(createMinutes());
		timetable->setDay(day);
		timetable->setStartTime(start_time);
		return timetable;
	}
};

class TrainTimetableFactory : public TimetableFactory {
		LastingTime* createMinutes() {
		return new TrainMinutes();
	}

	Timetable * createTimetable(string day, string start_time) {
		Timetable *timetable = new Timetable("Train");
		timetable->setMinutes(createMinutes());
		timetable->setDay(day);
		timetable->setStartTime(start_time);
		return timetable;
	}
};
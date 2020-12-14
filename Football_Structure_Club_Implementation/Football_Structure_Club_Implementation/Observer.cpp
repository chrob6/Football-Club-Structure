#include <string>
#include <iostream>
#include <vector>


using namespace std;

class Observer {
public:
	virtual void update() = 0;
};


class Subject {
public:
	virtual void addObservator(Observer &object) = 0;
	virtual void removeObservator(Observer &object) = 0;
protected:
	virtual void notifyObservators() = 0;
};
#ifndef CANDIDATE_H
#define CANDIDATE_H
#include <string>

using namespace std;


class Candidate {

//private:
public:
	int time_playing;
	string club;
	
//protected:
	string name;
	string surname;
	int age;
	string position;

public:
	Candidate() {
		//
	}
	Candidate(int _age, string _name, string _surname, string _position);
	Candidate(int _age, int _time_playing, string _name, string _surname, string _club, string _position);
	//login_can();
	
};

#endif

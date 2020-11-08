#ifndef CANDIDATE_H
#define CANDIDATE_H

using namespace std;

class Candidate {

private:
	int age;
	int time_playing;
	string name;
	string surname;
	string club;
	string position;

public:
	Candidate(int _age, int _time_playing, string _name, string _surname, string _club, string _position ) {
		age = _age;
		time_playing = _time_playing;
		name = _name;
		surname = _surname;
		club = _club;
		position = _position;
	}
};

#endif

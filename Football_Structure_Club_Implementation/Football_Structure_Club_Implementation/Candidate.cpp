#include "Candidate.h"

Candidate::Candidate(int _age, int _time_playing, string _name, string _surname, string _club, string _position) {
	age = _age;
	time_playing = _time_playing;
	name = _name;
	surname = _surname;
	club = _club;
	position = _position;


}

Candidate::Candidate(int _age, string _name, string _surname, string _position) {
	age = _age;
	name = _name;
	surname = _surname;
	position = _position;
}

void Candidate::Show() {
	cout << endl;
	cout << "Imie: " << name << endl;
	cout << "Nazwisko: " << surname << endl;
	cout << "Wiek: " << age << endl;
	cout << "Kariera w latach: " << time_playing << endl;
	cout << "Aktualny klub: " << club << endl;
	cout << "Pozycja: " << position << endl;
	cout << endl;
}
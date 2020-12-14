#include "Coach.h"
#include <iostream>
#include <mysql.h>
#include "Football_player.h"
#include "Timetable.h"

void Coach::updateSalary(float bonus) {
	salary += bonus;
}

void Coach::login_coach(vector<Football_player> &base_players, vector<Timetable> &timetable_phy, vector<Timetable> &timetable_train) {
	while (1) {

		for (Observer* o :timetable_train[0].Getobservers()) {
			cout << o << endl;
		}

		int choice1;
		cout << endl;
		cout << " WYBIERZ CO CHCESZ ZROBIC: " << endl;
		
		cout << "- Zmiana statystyk zawodnika 1" << endl;
		cout << "- Zobaczenie statystyk zawodnika 2 " << endl;
		cout << "- Zobaczenie terminarza 3 " << endl;
		cout << "- Zmiana terminarza 4 " << endl;
		cout << "- Wyjdz 5 " << endl;
		cout << "Wybierz (1-5): ";
		cin >> choice1;

		if (choice1 == 1) {
			int number;

			cout << "Podaj numer zawodnika: ";
			cin >> number;
			for (int i = 0; i < base_players.size(); i++) {
				if (base_players[i].Getnumber() == number) {
					int m, g;
					base_players[i].progressCheck();
					cout << "Zmiana dla zawodnika o numerze: " << base_players[i].Getnumber() << endl;
					cout << "Podaj minuty: ";
					cin >> m;
					base_players[i].SetMin(m);
					cout << "Podaj gole: ";
					cin >> g;
					base_players[i].SetGoals(g);
					base_players[i].progressCheck();
				}
			}
			//pobranie zawodnika i wrzucenie do obiektu

		}
		//podanie danych kandydata
		else if (choice1 == 2) {
			int number;

			cout << "Podaj numer zawodnika: ";
			cin >> number;
			for (Football_player p : base_players) {
				if (p.Getnumber() == number) {
					cout << "Number zawodnika " << p.Getnumber() << " " << endl;
					p.progressCheck();
				}
			}
			
		}
		else if (choice1 == 3) {
			cout << "Jednostki treningowe: " << endl;
			for (Timetable t : timetable_train) {
				t.show();
			}
		}
		else if (choice1 == 4) {
			string d;
			cout << "W ktorym dniu zmienic trening? (po ang. np Monday): ";
			cin >> d;

			for (int i = 0; i < timetable_train.size(); i++) {
				if (timetable_train[i].GetDay() == d) {
					string h;
					int time;
					cout << "Podaj godzine (w formie HH:MM:SS): ";
					cin >> h;
					//cout << "Podaj czas trwania w min: ";
					//cin >> time;
					timetable_train[i].update(h);
				}
			}
			for (Timetable t : timetable_train) {
				t.show();
			}

				}
		else if (choice1 == 5) {
					break;
				}
		}
	}
	

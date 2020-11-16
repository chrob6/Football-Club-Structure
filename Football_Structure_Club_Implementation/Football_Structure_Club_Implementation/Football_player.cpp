#include "Football_player.h"

//void Football_player::progressCheck(int goals, int minutes) {
//	cout << "Goals scored: " << goals << endl;
//	cout << "Minutes played: " << minutes;
//}

void Football_player::progressCheck() {
	cout << endl << "Goals scored: " << goals << endl;
	cout << "Minutes played: " << minutes_played << endl << endl;
}

int Football_player::Getnumber() {
	return number;
}

void Football_player::SetGoals(int _goals) {
	goals += _goals;
}

void Football_player::SetMin(int _min) {
	minutes_played += _min;
}

int Football_player::GetStats() {
	// TODO - implement Football_player::GetStats
	throw "Not yet implemented";
}

void Football_player::InsertStats(int _goals, int _minutes) {
	goals += _goals;
	minutes_played += _minutes;
}

void Football_player::updateSalary(float bonus) {
	salary += bonus;
}

void Football_player::login_player(vector<Timetable> &timetable_phy, vector<Timetable> &timetable_train) {
	while (1) {
		int choice1;
		cout << endl;
		cout << " WYBIERZ CO CHCESZ ZROBIC: " << endl;

		cout << "- Zobaczenie swojego progresu 1" << endl;
		cout << "- Zobaczenie terminarz treningow 2 " << endl;
		cout << "- Umowienie do fizjoterapeuty 3 " << endl;
		cout << "- Wyjdz 4 " << endl;
		cout << "Wybierz (1-4): ";
		cin >> choice1;

		if (choice1 == 1) {
			
			progressCheck();
			//pobranie zawodnika i wrzucenie do obiektu

		}
		//podanie danych kandydata
		else if (choice1 == 2) {
			cout << "Jednostki treningowe: " << endl;
			for (Timetable t : timetable_train) {
				t.show();
			}
		}
		else if (choice1 == 3) {
			string h, d;
			int time;
			cout << "Jednostki treningowe: " << endl;
			for (Timetable t : timetable_train) {
				t.show();
			}

			cout << endl << "Kalendarz fizjoterapeuty: " << endl;
			for (Timetable t : timetable_phy) {
				t.show();
			}
			cout << "Podaj dzien(po ang. np Monday): ";
			cin >> d;
			cout << "Podaj godzine (w formie HH:MM:SS): ";
			cin >> h;
			cout << "Podaj czas trwania w min: ";
			cin >> time;

			Timetable appointment(d, time, h);
			timetable_phy.push_back(appointment);
		}
		else if (choice1 == 4) {
			break;
		}
	}
}

#include "Physiotherapist.h"

void Physiotherapist::login_phy(vector<Timetable> &timetable_phy) {
	while (1) {
		int choice1;
		cout << endl;
		cout << " WYBIERZ CO CHCESZ ZROBIC: " << endl;

		cout << "- Zmiana terminu wizyt 1" << endl;
		cout << "- Zobaczenie terminarz wizyt 2 " << endl;
		cout << "- Wyjdz 3 " << endl;
		cout << "Wybierz (1-3): ";
		cin >> choice1;

		if (choice1 == 1) {
			string d, h;
			int time;
			cout << "Terminy wizyt: " << endl;
			for (Timetable t : timetable_phy) {
				t.show();
			}
			cout << "Podaj dzien(po ang. np Monday): ";
			cin >> d;
			cout << "Podaj godzine (w formie HH:MM:SS): ";
			cin >> h;
			
			for (int i = 0; i < timetable_phy.size(); i++) {
				if (timetable_phy[i].GetDay() == d && timetable_phy[i].GetTime() == h) {
					cout << "Podaj dzien do zmiany(po ang. np Monday): ";
					cin >> d;
					cout << "Podaj godzine do zmiany (w formie HH:MM:SS): ";
					cin >> h;
					cout << "Podaj czas trwania w min: ";
					cin >> time;
					timetable_phy[i].update(time, h, d);
				}
			}

			cout << "Terminy wizyt: " << endl;
			for (Timetable t : timetable_phy) {
				t.show();
			}
			

		}
		else if (choice1 == 2) {
			cout << "Terminy wizyt: " << endl;
			for (Timetable t : timetable_phy) {
				t.show();
			}
		}
		else if (choice1 == 3) {
			break;
		}
	}
}
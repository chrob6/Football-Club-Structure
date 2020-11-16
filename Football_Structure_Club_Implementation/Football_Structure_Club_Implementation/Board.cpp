#include "Board.h"
#include "Football_player.h"
#include "Candidate.h"

void Board::dismissal(Football_player player) {
	// TODO - implement Board::dismissal
	throw "Not yet implemented";
}

void Board::newplayer(Candidate candidate) {
	// TODO - implement Board::newPlayer
	throw "Not yet implemented";
}

void Board::bonus() {
	// TODO - implement Board::bonus
	throw "Not yet implemented";
}

void Board::login_board(vector<Candidate> &base_candidates, vector<Football_player> &base_players, Coach &coach) {
	while (1) {
		
		int choice1;
		cout << endl;
		cout << " WYBIERZ CO CHCESZ ZROBIC: " << endl;

		cout << "- Przeglad kandydatow 1" << endl;
		cout << "- Udzielenie premii 2 " << endl;
		cout << "- Zwolnienie zawodnika 3 " << endl;
		cout << "- Wyjdz 4 " << endl;
		cout << "Wybierz (1-4): ";
		cin >> choice1;

		if (choice1 == 1) {
			int decision;
			int size = base_candidates.size();
			for (int i = 0; i < size; i++) {
				base_candidates[i].Show();
				
				cout << "- Przyjmij do druzyny 1" << endl;
				cout << "- Odrzuc 2 " << endl;
				cout << "- Pomin 3 " << endl;
				cout << "Wybierz (1-3): ";
				cin >> decision;
				if (decision == 1) {
					int number = base_players.size() + 1;
					int sal; 
					cout << "Stawka dla gracza: ";
					cin >> sal;
					Football_player p(number, sal, base_candidates[i].age, base_candidates[i].name, base_candidates[i].surname, base_candidates[i].position);
					base_players.push_back(p);
				}
				else if (decision == 2) {
					base_candidates.erase(base_candidates.begin() + i);
				}
			}
		}
		//podanie danych kandydata
		else if (choice1 == 2) {
			int number, coach_or_player;
			double bonus;

			for (Football_player p : base_players) {
				cout << "Number zawodnika " << p.Getnumber() << " " << endl;
				p.progressCheck();
			}


			cout << "Podaj numer zawodnika dla udzielenia premii - jeœli premia dla trenera to nr 100: ";
			cin >> number;
			cout << "Kwota premii: ";
			cin >> bonus;
			if (number == 100) {
				coach.updateSalary(bonus);
			}
			else {
				for (int i = 0; i < base_players.size(); i++) {
					if (base_players[i].Getnumber() == number) {
						base_players[i].updateSalary(bonus);
					}
				}
			}
			

		}
		else if (choice1 == 3) {
			int number;

			cout << "Podaj numer zawodnika do zwolnienia: ";
			cin >> number;
			for (int i = 0; i < base_players.size(); i++) {
				if (base_players[i].Getnumber() == number) {
					base_players.erase(base_players.begin() + i);
				}
			}
		}
		else if (choice1 == 4) {
			break;
		}
	}
}

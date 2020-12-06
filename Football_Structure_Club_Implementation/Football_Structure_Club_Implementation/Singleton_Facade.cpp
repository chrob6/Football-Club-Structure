#include <iostream>
#include <fstream>
#include "Candidate.h"
#include "Football_player.h"
#include "Coach.h"
#include "Board.h"
#include "Timetable.h"
#include "Physiotherapist.h"
#include <mysql.h>
#include <vector>
#include <Windows.h>
#include "TimetableFactory.cpp"

using namespace std;



class Singleton_Facade {
private:
	int qstate;
	vector<Football_player> base_players;
	vector<Candidate> base_candidates;
	vector<Timetable> base_timetable_phy;
	vector<Timetable> base_timetable_train;


public:
	static Singleton_Facade& instance();

	void menu();
	void connect();
};

Singleton_Facade& Singleton_Facade::instance() {
	static Singleton_Facade instance_;
	return instance_;
}

void Singleton_Facade::menu() {
	connect();

	cout << "TEST: " << endl;
	for (Football_player p : base_players) {
		cout << p.position << endl;
	}

	for (Candidate c : base_candidates) {
		cout << c.club << endl;
	}
	cout << "TEST" << endl << endl;
	//for (Timetable t : base_timetable_phy) {
	//	cout << t.day << endl;
	//}

	//for (Timetable t : base_timetable_train) {
	//	cout << t.start_time << endl;
	//}

	while (1) {
		cout << " WYBIERZ CO CHCESZ ZROBIC: " << endl;
		//cin.get();
		int choice;
		cout << "- Zlozenie kandydatury 1" << endl;
		cout << "- Logowanie 2 " << endl;
		cout << "- Wyjdz 3 " << endl;
		cout << "Wybierz (1-3): ";
		cin >> choice;

		Coach coach;
		Board board;
		Physiotherapist physiotherapist;
		//Candidate test(6, 1034, "John", "Johnson", "Lech", "Striker");
		//Football_player fptest(3, 314, test.age, test.name, test.surname, test.position);
		string name, surname, position, club;
		int age, years;


		if (choice == 1) { // kandydat sklada swoja kandydature
			cout << "Podaj imie" << endl;
			cin >> name;
			cout << "Podaj nazwisko" << endl;
			cin >> surname;
			cout << "Podaj wiek" << endl;
			cin >> age;
			cout << "Podaj pozycje" << endl;
			cin >> position;
			cout << "Podaj ile lat grasz" << endl;
			cin >> years;
			cout << "Podaj byly klub" << endl;
			cin >> club;

			Candidate candidate(age, years, name, surname, club, position);
			base_candidates.push_back(candidate);
		}

		else if (choice == 2) {
			int id;
			cout << "Podaj id: ";
			cin >> id;
			if (id == 100) {
				coach.login_coach(base_players, base_timetable_phy, base_timetable_train);
			}
			else if (id < 100) {
				base_players[id - 1].login_player(base_timetable_phy, base_timetable_train);
			}
			else if (id == 111)
				physiotherapist.login_phy(base_timetable_phy);
			else if (id == 1000)
				board.login_board(base_candidates, base_players, coach);
		}
		else if (choice == 3) {

			cout << "TEST: " << endl;
			for (Football_player p : base_players) {
				cout << p.position << endl;
			}

			for (Candidate c : base_candidates) {
				cout << c.club << endl;
			}
			cout << "TEST" << endl << endl;


			cout << "B ";
			Sleep(500);
			cout << "Y ";
			Sleep(500);
			cout << "E " << endl;
			Sleep(1000);

			exit;
			break;
		}
	}
}

void Singleton_Facade::connect() {
	int qstate;
	MYSQL * conn;
	MYSQL_ROW row;
	MYSQL_RES *res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "fc", "fc", "fc", 3306, NULL, 0);
	string query;
	const char* q;

	if (conn) {
		//std::cout << "Success" << std::endl;

		query = "SELECT * FROM player";
		q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate) {
			res = mysql_store_result(conn);

			while (row = mysql_fetch_row(res)) {

				Football_player p(atoi(row[0]), atoi(row[4]), atoi(row[3]), row[1], row[2], row[7]);
				base_players.push_back(p);
			}
		}

		query = "SELECT * FROM candidate";
		q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate) {
			res = mysql_store_result(conn);

			while (row = mysql_fetch_row(res)) {

				Candidate c(atoi(row[3]), atoi(row[4]), row[1], row[2], row[5], row[6]);
				base_candidates.push_back(c);
			}
		}

		query = "SELECT * FROM timetable_phy";
		q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate) {
			res = mysql_store_result(conn);

			while (row = mysql_fetch_row(res)) {

				TimetableFactory* factory = new PhyTimetableFactory;
				Timetable *t = factory->createTimetable(row[1], row[3]);

				base_timetable_phy.push_back(*(t));
			}
		}

		query = "SELECT * FROM timetable_train";
		q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate) {
			res = mysql_store_result(conn);

			while (row = mysql_fetch_row(res)) {


				TimetableFactory* factory = new TrainTimetableFactory;
				Timetable *t = factory->createTimetable(row[1], row[3]);

				base_timetable_train.push_back(*(t));

				/*	Timetable t(row[1], atoi(row[2]), row[3]);
					base_timetable_train.push_back(t);*/
			}
		}
	}
}
#include <iostream>
#include <fstream>
#include "Candidate.h"
#include "Football_player.h"
#include "Coach.h"
#include "Board.h"
#include "Physiotherapist.h"
#include <mysql.h>

using namespace std;

int qstate;
void connect();

int main()
{
	connect();

	cout << " WYBIERZ CO CHCESZ ZROBIC: " << endl;
	//cin.get();
	int choice;
	cout<<"- Zlozenie kandydatury 1" <<endl;
	cout<<"- Logowanie 2 "<<endl;
	cout<<"- Wyjdz 3 "<<endl;
	cin>>choice;

	Coach coach;
	Board board;
	Physiotherapist physiotherapist;
	Candidate test(6, 1034, "John", "Johnson", "Lech", "Striker");
	Football_player fptest(3, 314, test.age, test.name, test.surname, test.position);
	string name, surname, position, club;
	int age, years;


	if (choice == 1) {
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
		Candidate can(age, years, name, surname, club, position);
	}
		//podanie danych kandydata
	else if (choice == 2) {
			int id;
			cout << "Podaj id";
			cin >> id;
			if (id < 100) {}
				//login_player(id);
			else if (id == 100)
				coach.login_coach();
			else if (id == 111) {}
				//login_phy();
			else if (id == 1000) {}
				//login_board();
	}
	else if (choice == 3) {
		
		cout<<"Bye"<<endl;
		exit;
	}

	//system("Pause");


	return 0;
}



void connect() {
	int qstate;
	MYSQL * conn;
	MYSQL_ROW row;
	MYSQL_RES *res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "fc", "fc", "fc", 3306, NULL, 0);

	if (conn) {
		std::cout << "Success" << std::endl;

		string query = "SELECT * FROM player";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate) {
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res)) {
				std::cout << row[0] << " " << row[1];
			}
		}
	}
}
#include "Coach.h"
#include <iostream>
#include <mysql.h>
#include "Football_player.h"
#include "Timetable.h"

void Coach::updateSalary(float bonus) {
	salary += bonus;
}

void Coach::login_coach() {
	int a = 1;

	while (a == 1) {
		int choice1;
		cout << " WYBIERZ CO CHCESZ ZROBIC: " << endl;
		//cin.get();

		cout << "- Zmiana statystyk zawodnika 1" << endl;
		cout << "- Zobaczenie statystyk zawodnika 2 " << endl;
		cout << "- Zobaczenie terminarza 3 " << endl;
		cout << "- Zmiana terminarza 4 " << endl;
		cout << "- Wyjdz 5 " << endl;
		cin >> choice1;
		/*Football_player p1(2, 2040, 23, "John", "Fast", "Wing");
		Football_player p2(3, 3020, 32, "Peter", "Slow", "Defender");
		Football_player p3(4, 51200, 21, "Marcin", "The Best", "WHY");*/

		if (choice1 == 1) {
			int numer;

			cout << "Podaj numer zawodnika";
			cin >> numer;
			//pobranie zawodnika i wrzucenie do obiektu

		}
		//podanie danych kandydata
		else if (choice1 == 2) {
			int numer;

			cout << "Podaj numer zawodnika: ";
			cin >> numer;

			int qstate;
			MYSQL * conn;
			MYSQL_ROW row;
			MYSQL_RES *res;
			conn = mysql_init(0);
			conn = mysql_real_connect(conn, "localhost", "fc", "fc", "fc", 3306, NULL, 0);

			if (conn) {

				string query = " SELECT * FROM player WHERE ID_user= " + to_string(numer);
				const char* q = query.c_str();
				qstate = mysql_query(conn, q);
				if (!qstate) {
					res = mysql_store_result(conn);
					row = mysql_fetch_row(res);

					Football_player p(atoi(row[0]), atoi(row[3]), 34, row[1], row[2], row[6]);
					p.progressCheck();
				}
			}
		}
		else if (choice1 == 3) {
			string day;
			cout << "Podaj Dzien tygodnia: ";
			cin >> day;

			int qstate;
			MYSQL * conn;
			MYSQL_ROW row;
			MYSQL_RES *res;
			conn = mysql_init(0);
			conn = mysql_real_connect(conn, "localhost", "fc", "fc", "fc", 3306, NULL, 0);

			if (conn) {

				string query = " SELECT * FROM timetable_train WHERE w_day= '" + day + "'";
				const char* q = query.c_str();
				qstate = mysql_query(conn, q);
				if (!qstate) {
					res = mysql_store_result(conn);
					row = mysql_fetch_row(res);

					Timetable t(row[1], atoi(row[2]), row[3]);
					t.show();
				}
			}
		}
		else if (choice1 == 4) {

				}
		else if (choice1 == 5) {
					break;
				}
		}
	}
	

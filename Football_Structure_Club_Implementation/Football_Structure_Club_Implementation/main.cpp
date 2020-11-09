#include <iostream>
#include <fstream>
#include <math.h>
#include "Candidate.h"
#include "Football_player.h"
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


	Candidate test(6, 1034, "John", "Johnson", "Lech", "Striker");
	Football_player fptest(3, 314, test.age, test.name, test.surname, test.position);

	switch(choice)
	{
		case 1:
		//podanie danych kandydata
			
		break;
		case 2:
		//logowanie
		break;
		case 3:
		cout<<"Bye"<<endl;
		exit;
		break;
	}

	system("Pause");


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

		std::string query = "SELECT * FROM player";
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
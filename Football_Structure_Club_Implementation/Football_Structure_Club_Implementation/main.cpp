#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include "Candidate.h"


using namespace std;


int main()
{
	cout << " WYBIERZ CO CHCESZ ZROBIC: " << endl;
	//cin.get();
	int choice;
	cout<<"- Zlozenie kandydatury 1" <<endl;
	cout<<"- Logowanie 2 "<<endl;
	cout<<"- Wyjdz 3 "<<endl;
	cin>>choice;

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


	return 0;
}


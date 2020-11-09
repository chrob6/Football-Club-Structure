#include "Coach.h"
#include<iostream>

void Coach::updateSalary(float bonus) {
	salary += bonus;
}

void Coach::login_coach(){
int a=1;
while(a==1){
int choice1;
cout << " WYBIERZ CO CHCESZ ZROBIC: " << endl;
	//cin.get();
int choice1;
cout<<"- Zmiana statystyk zawodnika 1" <<endl;
cout<<"- Zobaczenie statystyk zawodnika 2 "<<endl;
cout<<"- Zmiana terminarza 3 "<<endl;
cout<<"- Wyjdz 4 "<<endl;
cin>>choice1;


switch(choice1){
	case 1:
	int numer;
	cout<<"Podaj numer zawodnika";
	cin>>numer;
	//pobranie zawodnika i wrzucenie do obiektu
	break;
	case 2:

	break;
	case 3:

 	break;
	case 4:
	a=0;
	break;

}
}

}
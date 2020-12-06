#include <iostream>
#include "Singleton_Facade.cpp"

using namespace std;


int main()
{
	Singleton_Facade::instance().menu();
	cout << "ytoyo";
	system("Pause");
	return 0;
}



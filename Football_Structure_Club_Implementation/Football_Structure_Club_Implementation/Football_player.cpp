#include "Football_player.h"

void Football_player::progressCheck(int goals, int minutes) {
	cout << "Goals scored: " << goals << endl;
	cout << "Minutes played: " << minutes;
}

int Football_player::Getnumber() {
	return number;
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

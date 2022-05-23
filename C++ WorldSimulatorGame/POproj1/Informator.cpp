#include "Informator.h"


void Informator::dodajInfocjmacje(string info) {
	informacje.push_back(info);
}

void Informator::wypiszInfoirmacje() {
	for (int i = 0; i < informacje.size(); i++) {
		cout << informacje[i];
	}
}

void Informator::usunInformacje() {
	informacje.clear();
}
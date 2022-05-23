#include "Mlecz.h"

Mlecz::Mlecz(Punkt polozenie, Swiat* swiat)
	:Roslina(0, 0, 'M', 0, true, Organizmy::mlecz, polozenie, swiat) {
	this->sila = 0;
	this->inicjatywa = 0;
	this->znak = 'M';
	this->wiek = 0;
}
string Mlecz::getNazwaOrganizmu() {
	return "Mlecz";
}

void Mlecz::akcja() {
	this->wiek++;
	ogolneInformacje();
	int i = 0;
	//cout << this->getNazwaOrganizmu() << " ";
	while (true) {
		i++;
		int x = rand() % 10;
		if (x < 1) {
			Rozprzestrzenianie();
			//cout << "Rozprzestrzenia sie!" << endl;
			break;
		}
		if (i == 3) {
			i++;
			break;
		}
	}
	if (i == 4) {
		swiat->info.dodajInfocjmacje(" Nie udalo sie rozprzestrzenic " );
		//cout << " Nie udalo sie rozprzestrzenic " << endl;
	}
	swiat->info.dodajInfocjmacje("\n");
}
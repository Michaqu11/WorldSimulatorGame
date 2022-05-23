#include "Lis.h"
#include "Informator.h"

Lis::Lis(Punkt polozenie, Swiat* swiat)
	:Zwierze(3, 7, 'L', 0, true, Organizmy::wilk, polozenie, swiat) {
	this->sila = 3;
	this->inicjatywa = 7;
	this->znak = 'L';
	this->wiek = 0;
}
string Lis::getNazwaOrganizmu() {
	return "Lis";
}
void Lis::akcja() {
	this->wiek++;
	//cout << "Punkt 1: to -> " << stary.getX() << " " << stary.getY() << endl;
	ogolneInformacje();
	//cout << this->getNazwaOrganizmu() << " ";
	//cout << " Ma sily: " << this->getSila() << endl;
	Punkt p = losujPunktDlaLisa();
	if (this->polozenie != p) {
		if (swiat->czyPustePole(p.getX(), p.getY())) {
			Move(p);
		}
		else {
			//cout << " 1) " << p.getX() << " " << p.getY() << endl;
			//cout << swiat->getMapaSwiata()[p.getY()][p.getX()]->getZnak() << endl;
			bool ruch = true;
			kolizja(swiat->getMapaSwiata()[p.getY()][p.getX()], true, &ruch);
			if (this->zycie && swiat->czyPustePole(p.getX(),p.getY()) && ruch) {
				//cout << "uauau" << endl;
				Move(p);
				//swiat->Ruch(this, p);
			}
		}
	}
	swiat->info.dodajInfocjmacje("\n");
}
Punkt Lis::losujPunktDlaLisa() {
	Punkt p = this->getPolozenie();
	//swiat->getMapaSwiata()[p.getY()][p.getX()]->getZnak()
	Punkt p2 = p;
	bool e = false;
	bool sprawdzonaPozycja[4] = { false };
	while (!e) {
		int x = rand() % 4;
		switch (x) {

		case 0: // gora
			if (p.getY() != 0) {
				p2.setY(p.getY() - 1);
				p2.setX(p.getX());
				//cout << " gora " << endl;
			}
			sprawdzonaPozycja[0] = true;
			break;

		case 1: // dol
			if (p.getY() != swiat->getHeight() - 1) {
				p2.setY(p.getY() + 1);
				p2.setX(p.getX());
				//cout << " dol " << endl;
			}
			sprawdzonaPozycja[1] = true;

			break;

		case 2: // lewo
			if (p.getX() != 0) {
				p2.setY(p.getY());
				p2.setX(p.getX() - 1);
				//cout << " lewo " << endl;
			}
			sprawdzonaPozycja[2] = true;
			break;

		case 3: // prawo
			if (p.getX() != swiat->getWidth() - 1) {
				p2.setY(p.getY());
				p2.setX(p.getX() + 1);
				//cout << " prawo " << endl;
			}
			sprawdzonaPozycja[3] = true;
			break;
		}

		bool wszystkieSprawdzone = true;
		if (p2 != p) {
			if (swiat->czyPustePole(p2.getX(), p2.getY())) {
				e = true;
			}
			else if (swiat->getMapaSwiata()[p2.getY()][p2.getX()]->getSila() <= this->sila) {
				e = true;
			}
		}
		if (!e) {
			for (int i = 0; i < 4; i++) {
				if (!sprawdzonaPozycja[i]) {
					wszystkieSprawdzone = false;
				}
			}
			if (wszystkieSprawdzone) {
				e = true;
				p2 = p;
			}
		}
	}
	
	if (p2.getX() == p.getX() && p2.getY() == p.getY()) {
		swiat->info.dodajInfocjmacje("Zostaje w miejscu na polu " + to_string(p.getX()) + " " + to_string(p.getY()));
		//cout << " Zostaje w miejscu na polu " << p.getX() << " " << p.getY() << endl;
	}
	else {
		//cout << " Z pola " << p.getX() << " " << p.getY();
		//cout << " na pole: " << p2.getX() << " " << p2.getY() << endl;
	}
	return p2;

}
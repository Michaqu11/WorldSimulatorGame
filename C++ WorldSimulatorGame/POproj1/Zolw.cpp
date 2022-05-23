#include "Zolw.h"

Zolw::Zolw(Punkt polozenie, Swiat* swiat)
	:Zwierze(2, 1, 'Z', 0, true, Organizmy::zolw, polozenie, swiat) {
	this->sila = 2;
	this->inicjatywa = 1;
	this->znak = 'Z';
	this->wiek = 0;
}
string Zolw::getNazwaOrganizmu() {
	return "Zolw";
}

void Zolw::akcja() {
	this->wiek++;
	ogolneInformacje();
	//cout << this->getNazwaOrganizmu() << " ";
	//cout << " Ma tyle sily: " << this->getSila() << endl;
	Punkt p = losujPunktDlaZolwia();
	if (p != this->polozenie) {
		if (swiat->czyPustePole(p.getX(), p.getY())) {
			Move(p);
			//swiat->Ruch(this, p);
		}
		else {
			//cout << " 1) " << p.getX() << " " << p.getY() << endl;
			//cout << swiat->getMapaSwiata()[p.getY()][p.getX()]->getZnak() << endl;
			bool ruch = true;
			kolizja(swiat->getMapaSwiata()[p.getY()][p.getX()], true, &ruch);
			if (this->zycie && swiat->getMapaSwiata()[p.getY()][p.getX()] == nullptr && ruch) {
				//cout << "uauau" << endl;
				Move(p);
				//swiat->Ruch(this, p);
			}
		}
	}
	swiat->info.dodajInfocjmacje("\n");
}

void Zolw::kolizja(Organizm* other, bool atakujacy, bool* ruch) {
	//cout << " 2) " << other->getPolozenie().getX() << " " << other->getPolozenie().getY() << endl;

	if (this->getRodzajOrganizmu() == other->getRodzajOrganizmu()) {
		//std::cout << " bara bara " << std::endl;
		Rozmnazanie();
	}
	else {
		if (this->getSila() > other->getSila() || (this->getSila() == other->getSila() && atakujacy)) {
			other->kolizja(this, false, ruch);
		}
		else if (other->getSila() < 5) {
			swiat->info.dodajInfocjmacje(" Zolw zatrzymuje atak! ");
				//cout << "ruuch" << endl;
				*ruch = false;
		}
		else {
			zabojczeInformacjeDlaZwierzat(other);
			//std::cout << other->getZnak() <<  " z sila: "<< other->getSila() <<  " zabil -> " << this->getZnak() << " z sila: " << this->getSila() << std::endl;
			swiat->wyczyscOrganizmZMapy(this->polozenie);
			//swiat->ZabijOrganizm(other);
			//other->kolizja(this, false);
		}
	}
}
Punkt Zolw::losujPunktDlaZolwia() {
	Punkt p = this->getPolozenie();
	//swiat->getMapaSwiata()[p.getY()][p.getX()]->getZnak()
	int y = rand() % 4;
	if (y == 0) {
		//cout << " idzie z pola " << p.getX() << " " << p.getY();
		Punkt p2;
		bool e = false;
		while (!e) {
			int x = rand() % 4;
			switch (x) {

			case 0: // gora
				if (p.getY() != 0) {
					p2.setY(p.getY() - 1);
					p2.setX(p.getX());
					e = true;
				}
				break;
			case 1: // dol
				if (p.getY() != swiat->getHeight() - 1) {
					p2.setY(p.getY() + 1);
					p2.setX(p.getX());
					e = true;
				}
				break;
			case 2: // lewo
				if (p.getX() != 0) {
					p2.setY(p.getY());
					p2.setX(p.getX() - 1);
					e = true;
				}
				break;

			case 3: // prawo
				if (p.getX() != swiat->getWidth() - 1) {
					p2.setY(p.getY());
					p2.setX(p.getX() + 1);
					e = true;
				}
				break;
			}
		}
		//cout << " na pole: " << p2.getX() << " " << p2.getY() << endl;
		return p2;
	}
	else {
		swiat->info.dodajInfocjmacje(" zostaje w miejscu: " + to_string(p.getX()) + " " + to_string(p.getY()));
		//cout << " Zostaje w miejscu na polu: "<<p.getX() << " " << p.getY() << endl;
	}

	return p;

}

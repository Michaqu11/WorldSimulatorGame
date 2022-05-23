#include "Antylopa.h"


Antylopa::Antylopa(Punkt polozenie, Swiat* swiat)
	:Zwierze(4, 4, 'A', 0, true, Organizmy::antylopa, polozenie, swiat) {
	this->sila = 4;
	this->inicjatywa = 4;
	this->znak = 'A';
	this->wiek = 0;
}
string Antylopa::getNazwaOrganizmu() {
	return "Antylopa";
}
void Antylopa::akcja() {
	this->wiek++;
	ogolneInformacje();
	//cout << this->getNazwaOrganizmu() << " ";
	//cout << " Ma sily: " << this->getSila() << endl;
	Punkt p = losujPunktDlaAntylopy();
	this->wiek++;
	if (swiat->czyPustePole(p.getX(), p.getY())) {
		Move(p);
	}
	else {
		//cout << " 1) " << p.getX() << " " << p.getY() << endl;
		//cout << swiat->getMapaSwiata()[p.getY()][p.getX()]->getZnak() << endl;
		bool ruch = true;
		kolizja(swiat->getMapaSwiata()[p.getY()][p.getX()], true, &ruch);
		if (this->zycie && swiat->czyPustePole(p.getX(), p.getY()) && ruch) {
			Move(p);
			//swiat->Ruch(this, p);
		}
	}
	swiat->info.dodajInfocjmacje("\n");
}
void Antylopa::kolizja(Organizm* other, bool atakujacy, bool* ruch) {
	//cout << " 2) " << other->getPolozenie().getX() << " " << other->getPolozenie().getY() << endl;
	if (other->getZycie()) {
		if (this->getRodzajOrganizmu() == other->getRodzajOrganizmu()) {
			//std::cout << " bara bara " << std::endl;
			Rozmnazanie();
		}
		else {
			if (this->getSila() > other->getSila() || (this->getSila() == other->getSila() && atakujacy)) {
				other->kolizja(this, false, ruch);
			}
			else {
				int x = rand() % 2;
				if (x == 0) {
					Punkt p = this->znajdzWolnyPunktDlaAntylopy();
					swiat->info.dodajInfocjmacje(" Antylopie Udalo sie zrobic unik! ");
					//cout << " ( unik ) ";
					Move(p);
					//*ruch = false;
				}
				else {
					zabojczeInformacjeDlaZwierzat(other);
					//swiat->info.dodajInfocjmacje(" " + other->getNazwaOrganizmu() + " z sila: " + to_string(other->getSila()) + " zabil -> " + this->getNazwaOrganizmu() + " z sila: " + to_string(this->getSila()));
					//std::cout << other->getZnak() << " z sila: " << other->getSila() << " zabil -> " << this->getZnak() << " z sila: " << this->getSila() << std::endl;
					swiat->wyczyscOrganizmZMapy(this->polozenie);
					//swiat->ZabijOrganizm(other);
					//other->kolizja(this, false);
				}
			}
		}
	}
}


Punkt Antylopa::losujPunktDlaAntylopy() {
	Punkt p = this->getPolozenie();
	//swiat->getMapaSwiata()[p.getY()][p.getX()]->getZnak()
	Punkt p2;
	bool e = false;
	while (!e) {
		int x = rand() % 8;
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
		case 4: // gora*2
			if (p.getY()-1 > 0 ) {
				p2.setY(p.getY() - 2);
				p2.setX(p.getX());
				e = true;
			}
			break;
		case 5: // dol*2
			if (p.getY()+1 < swiat->getHeight() - 1) {
				p2.setY(p.getY() + 2);
				p2.setX(p.getX());
				e = true;
			}
			break;
		case 6: // lewo*2
			if (p.getX()-1 > 0) {
				p2.setY(p.getY());
				p2.setX(p.getX() - 2);
				e = true;
			}
			break;

		case 7: // prawo*2
			if (p.getX()+1 < swiat->getWidth() - 1) {
				p2.setY(p.getY());
				p2.setX(p.getX() + 2);
				e = true;
			}
			break;
		}
	}
		//cout << " Z pola " << p.getX() << " " << p.getY();
		//cout << " na pole: " << p2.getX() << " " << p2.getY() << endl;
	return p2;
}
Punkt Antylopa::znajdzWolnyPunktDlaAntylopy() {

	Punkt p = this->polozenie;
	Punkt p2 = p;
	
		if (p.getY() != 0 && swiat->czyPustePole(p.getX(), p.getY() - 1 )) {
			p2.setY(p.getY() - 1);
			p2.setX(p.getX());
		}
		else if (p.getY() != swiat->getHeight() - 1 && swiat->czyPustePole(p.getX(), p.getY() + 1)) {
			p2.setY(p.getY() + 1);
			p2.setX(p.getX());
		}
		else if (p.getX() != 0 && swiat->czyPustePole(p.getX() - 1, p.getY())) {
			p2.setY(p.getY());
			p2.setX(p.getX() - 1);
		}
		else if (p.getX() != swiat->getWidth() - 1 && swiat->czyPustePole(p.getX() + 1, p.getY())) {
			p2.setY(p.getY());
			p2.setX(p.getX() + 1);
		}
		return p2;
}
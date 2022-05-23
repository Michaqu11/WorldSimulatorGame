#include "Zwierze.h"
#include <iostream>
#include <windows.h>

using namespace std;

Zwierze::Zwierze(int sila, int inicjatywa, char znak, int wiek, bool zycie, Organizmy organizm, Punkt polozenie, Swiat* swiat)
	:Organizm(sila, inicjatywa, znak, wiek, zycie, organizm, polozenie, swiat) {

}



void Zwierze::akcja() {
	this->wiek++;
	ogolneInformacje();
	//cout << this->getZnak() << " ";
	Punkt p = wylosujPunktObok();
	if (swiat->czyPustePole(p.getX(),p.getY())) {
		//cout << "M1" << endl;
		Move(p);
	}
	else {
		//cout << " 1) " << p.getX() << " " << p.getY() << endl;
		//cout << swiat->getMapaSwiata()[p.getY()][p.getX()]->getZnak() << endl;
		bool ruch = true;
		kolizja(swiat->getMapaSwiata()[p.getY()][p.getX()], true, &ruch);
		if (this->zycie && swiat->czyPustePole(p.getX(),p.getY()) && ruch) {
			//cout << "M2" << endl;
			Move(p);
			//swiat->Ruch(this, p);
		}
	}
	swiat->info.dodajInfocjmacje("\n");
}
void Zwierze::kolizja(Organizm* other, bool atakujacy, bool* ruch) {
	//cout << " 2) " << other->getPolozenie().getX() << " " << other->getPolozenie().getY() << endl;

	if (this->getRodzajOrganizmu() == other->getRodzajOrganizmu()) {
		//std::cout << " bara bara " << std::endl;
		Rozmnazanie();
	}
	else {
		if (this->getSila() > other->getSila() || (this->getSila() == other->getSila() && atakujacy)) {
				other->kolizja(this, false, ruch);
		}
		else {
			zabojczeInformacjeDlaZwierzat(other);
			//std::cout << other->getZnak() << " z sila: " << other->getSila() << " zabil -> " << this->getZnak() << " z sila: " << this->getSila() << std::endl;
			swiat->wyczyscOrganizmZMapy(this->polozenie);
			//swiat->ZabijOrganizm(other);
			//other->kolizja(this, false);
		}
	}



		/*if (this->getZnak() == other->getZnak()) {
			std::cout << " bara bara " << std::endl;
			Rozmnazanie();
		}
		else {
			if (other->getZnak() == 'Z' && this->sila < 5) {
				cout << "ruuch" << endl;
				*ruch = false;
			}
			else if (other->getZnak() == 'G') {
				this->setSila(this->getSila() + 3);
				swiat->getMapaSwiata()[other->getPolozenie().getY()][other->getPolozenie().getX()] = nullptr;
				other->setZycie(false);
			}
			else if (other->getZnak() == 'J' || other->getZnak() == 'B') {
				swiat->getMapaSwiata()[this->getPolozenie().getY()][this->getPolozenie().getX()] = nullptr;
				this->setZycie(false);
				*ruch = false;
			}
			else if (this->sila > other->getSila() || (this->sila == other->getSila() && atakujacy)) {
				if (other->getZnak() == 'A') {
					other->kolizja(this,false, ruch);
				}
				std::cout << this->getZnak() << " 1) zabil -> " << other->getZnak() << std::endl;
				swiat->getMapaSwiata()[other->getPolozenie().getY()][other->getPolozenie().getX()] = nullptr;
				other->setZycie(false);
				//swiat->ZabijOrganizm(other);
				//other->kolizja(this, false);
			}
			else {
				//other->kolizja(this, false);
				std::cout << other->getZnak() << " 2) zabil -> " << this->getZnak() << std::endl;
				swiat->getMapaSwiata()[this->getPolozenie().getY()][this->getPolozenie().getX()] = nullptr;
				this->setZycie(false);
				//swiat->ZabijOrganizm(this);
			}

		}*/
}
Punkt Zwierze::wylosujPunktObok() {
	Punkt p = this->getPolozenie();
	//swiat->getMapaSwiata()[p.getY()][p.getX()]->getZnak()
	//cout  << " Z pola " << p.getX() << " " << p.getY();
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
			if (p.getY() != swiat->getHeight()-1) {
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
			if (p.getX() != swiat->getWidth()-1) {
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

void Zwierze::Move(Punkt nowy) {
	//std::cout << " 4) " << nowy.getX() << " " << nowy.getY() << std::endl;

	//cout << " nullowanie " << stary.getX() << " " << stary.getY() << endl;

	Punkt stary = this->polozenie;
	//cout << " idzie z pola " << stary.getX() << " " << stary.getY();
	swiat->getMapaSwiata()[stary.getY()][stary.getX()] = nullptr;
	swiat->getMapaSwiata()[nowy.getY()][nowy.getX()] = this;
	this->polozenie.setX(nowy.getX());
	this->polozenie.setY(nowy.getY());
	swiat->info.dodajInfocjmacje(" idzie na pole: " + to_string(nowy.getX()) + " " + to_string(nowy.getY()));
	//cout << " idzie na pole: " << nowy.getX() << " " << nowy.getY() << endl;

	//cout << swiat->getMapaSwiata()[stary.getY()][stary.getY()]->getZnak() << endl;
	//if (swiat->getMapaSwiata()[stary.getY()][stary.getY()] == nullptr) {
		//cout << "jest null" << endl;
	//}
}


void Zwierze::rysowanie() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	cout << this->znak;
	SetConsoleTextAttribute(hConsole, 7);
}

void Zwierze::Rozmnazanie() {
	Punkt p2 = znajdzWolnyPunktObok(this->polozenie);
	if (!(p2.getX() == this->polozenie.getX() && p2.getY() == this->polozenie.getY())) {
		//cout << " TEST " << endl;
		swiat->info.dodajInfocjmacje(" Rozmnaza sie! Powstaje nowe zwierze na polu: " + to_string(p2.getX()) + " " + to_string(p2.getY()));
		//cout << " Powstaje nowe zwierze na polu: " << p2.getX() << " " << p2.getY() << endl;
		swiat->stworzZwierze(p2, this->getZnak());
	}
}
Punkt Zwierze::znajdzWolnyPunktObok(Punkt p) {
	Punkt p2 = p;
	if (p.getY() != 0 && swiat->czyPustePole(p.getX(), p.getY() - 1)) {
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

Zwierze::~Zwierze(){
}
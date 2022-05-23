#include "Czlowiek.h"
#include <Windows.h>

Czlowiek::Czlowiek(Punkt polozenie, Swiat* swiat)
	:Zwierze(5, 4, 'C', 0, true, Organizmy::czlowiek, polozenie, swiat) {
	this->sila = 5;
	this->inicjatywa = 4;
	this->znak = 'C';
	this->wiek = 0;
	this->ileOdejmowac = 0;
}
string Czlowiek::getNazwaOrganizmu() {
	return "Czlowiek";
}
void Czlowiek::akcja() {
	this->wiek++;
	//cout << "Punkt 1: to -> " << stary.getX() << " " << stary.getY() << endl;
	ogolneInformacje();
	//cout << this->getNazwaOrganizmu() << " ";
	//cout << " Ma tyle sily: " << this->getSila() << endl;
	//cout << " Z pola " << getPolozenie().getX() << " " << getPolozenie().getY();
	Punkt p = swiat->getNastepnyPunktCzlowieka();
	if (swiat->czyPustePole(p.getX(), p.getY())) {
		//cout << "M1" << endl;
		Move(p);
		swiat->setPunktCzlowieka(p);
		//swiat->Ruch(this, p);
	}
	else {
		//cout << " 1) " << p.getX() << " " << p.getY() << endl;
		//cout << swiat->getMapaSwiata()[p.getY()][p.getX()]->getZnak() << endl;
		bool ruch = true;
		kolizja(swiat->getMapaSwiata()[p.getY()][p.getX()], true, &ruch);
		if (this->getZycie() && swiat->czyPustePole(p.getX(), p.getY()) && ruch) {
			//cout << "M2" << endl;
			Move(p);
			swiat->setPunktCzlowieka(p);
			//swiat->Ruch(this, p);
		}
	}
	if (ileOdejmowac > 0) {
		cout << " odajmowanie sily czlowiekowi " << endl;
		this->setSila(this->getSila() - 1);
		ileOdejmowac--;
	}
	swiat->info.dodajInfocjmacje("\n");
}
void Czlowiek::kolizja(Organizm* other, bool atakujacy, bool* ruch) {

	if (swiat->getCzySuperMocZostalaAktywowana()) {
		this->setSila(this->getSila() + swiat->getIloscTurDoSuperMocy());
		swiat->setCzySuperMocZostalaAktywowana(false);
		ileOdejmowac = swiat->getIloscTurDoSuperMocy();
	}

	if (this->getSila() > other->getSila() || (this->getSila() == other->getSila() && atakujacy)) {
		other->kolizja(this, false, ruch);
	}
	else {
		zabojczeInformacjeDlaZwierzat(other);
		//std::cout << other->getZnak() << " z sila: " << other->getSila() << " zabil -> " << this->getZnak() << " z sila: " << this->getSila() << std::endl;
		swiat->wyczyscOrganizmZMapy(this->polozenie);
		swiat->setZycieCzlowieka(false);
	}
}

void Czlowiek::rysowanie() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);
	cout << this->znak;
	SetConsoleTextAttribute(hConsole, 7);
}
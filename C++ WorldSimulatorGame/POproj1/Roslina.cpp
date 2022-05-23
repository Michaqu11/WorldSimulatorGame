#include "Roslina.h"
#include <windows.h>

Roslina::Roslina(int sila, int inicjatywa, char znak, int wiek, bool zycie, Organizmy organizm, Punkt polozenie, Swiat* swiat)
	:Organizm(sila, inicjatywa, znak, wiek, zycie, organizm, polozenie, swiat) {

}

void Roslina::akcja() {
	this->wiek++;
	ogolneInformacje();
	//cout << this->getZnak() << " ";
	//cout << " Ma tyle sily: " << this->getSila() << endl;
	//cout << " Z pola: " << this->polozenie.getX() << " " << this->polozenie.getY();
	int x = rand() % 10;
	if (x < 1) {
		Rozprzestrzenianie();
	}
	else {
		//cout << " Nie udalo sie rozprzestrzenic" << endl;
		swiat->info.dodajInfocjmacje(" Nie udalo sie rozprzestrzenic ");
	}
	swiat->info.dodajInfocjmacje("\n");
}
void Roslina::kolizja(Organizm* other, bool atakujacy, bool* ruch) {

	zabojczeInformacjeDlaRoslin(other);
	//std::cout << other->getZnak() << " z sila: " << other->getSila() << " zjadl -> " << this->getZnak() << " z sila: " << this->getSila() << std::endl;
	swiat->wyczyscOrganizmZMapy(this->polozenie);
}

void Roslina::Rozprzestrzenianie() {
	Punkt p2 = znajdzWolnyPunktObok(this->polozenie);
	if (p2 != this->getPolozenie()) {
		swiat->info.dodajInfocjmacje("Rozprzestrzenia sie! Powstaje nowa roslina na polu : " + to_string(p2.getX()) + " " + to_string(p2.getY()));
		//cout << " Powstaje nowa roslina na polu: " << p2.getX() << " " << p2.getY() << endl;
		swiat->stworzRosline(p2, this->getZnak());
	}
	else {
		swiat->info.dodajInfocjmacje(" Nie udalo sie rozprzestrzenic ");
	}
}
Punkt Roslina::znajdzWolnyPunktObok(Punkt p) {
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

void Organizm::rysowanie() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout << this->znak;
	SetConsoleTextAttribute(hConsole, 7);
}

Roslina::~Roslina() {
}
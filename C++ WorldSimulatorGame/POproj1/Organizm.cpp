#include "Organizm.h"

Organizm::Organizm( int sila, int inicjatywa, char znak, int wiek, bool zycie, Organizmy organizm, Punkt polozenie, Swiat* swiat) {
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->znak = znak;
	this->wiek = wiek;
	this->zycie = zycie;
	this->organizm = organizm;
	this->polozenie = polozenie;
	this->swiat = swiat;
}

int Organizm::getSila() {
	return sila;
}
int Organizm::getInicjatywa() {
	return inicjatywa;
}
int Organizm::getWiek() {
	return wiek;
}
char Organizm::getZnak() {
	return znak;
}
bool Organizm::getZycie() {
	return zycie;
}
Organizm::Organizmy Organizm::getRodzajOrganizmu() {
	return organizm;
}

Punkt Organizm::getPolozenie() {
	return polozenie;
}
Swiat* Organizm::getSwiat() {
	return swiat;
}

void Organizm::setSila(int sila) {
	this->sila = sila;
}
void Organizm::setInicjatywa(int inicjatywa) {
	this->inicjatywa = inicjatywa;
}
void Organizm::setWiek(int wiek) {
	this->wiek = wiek;
}
void Organizm::setZnak(char znak) {
	this->znak = znak;
}
void Organizm::setZycie(bool zycie) {
	this->zycie = zycie;
}
void Organizm::setRodzajOrganizmu(Organizmy organizm) {
	this->organizm = organizm;
}
void Organizm::setPolozenie(int x, int y) {
	polozenie.setX(x);
	polozenie.setY(y);
}
void Organizm::setSwiat(Swiat* swiat) {
	this->swiat = swiat;
}
void Organizm::ogolneInformacje() {
	swiat->info.dodajInfocjmacje(this->getNazwaOrganizmu() + " z pola: " + to_string(this->getPolozenie().getX()) + " " + to_string(this->getPolozenie().getY()) + " Ma sily: " + to_string(this->getSila()));
}
void Organizm::zabojczeInformacjeDlaZwierzat(Organizm* other) {
	swiat->info.dodajInfocjmacje(" " + other->getNazwaOrganizmu() + " z sila: " + to_string(other->getSila()) + " zabil -> " + this->getNazwaOrganizmu() + " z sila: " + to_string(this->getSila()));
}
void Organizm::zabojczeInformacjeDlaRoslin(Organizm* other) {
	swiat->info.dodajInfocjmacje(" " + other->getNazwaOrganizmu() + " z sila: " + to_string(other->getSila()) + " zjadl -> " + this->getNazwaOrganizmu() + " z sila: " + to_string(this->getSila()));
}
Organizm::~Organizm(){

}
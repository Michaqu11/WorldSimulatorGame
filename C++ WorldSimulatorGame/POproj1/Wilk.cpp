#include "Wilk.h"

Wilk::Wilk(Punkt polozenie, Swiat* swiat)
	:Zwierze(9, 5, 'W', 0 , true, Organizmy::wilk, polozenie, swiat) {
	this->sila = 9;
	this->inicjatywa = 5;
	this->znak = 'W';
	this->wiek = 0;
}
string Wilk::getNazwaOrganizmu() {
	return "Wilk";
}
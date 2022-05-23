#include "Trawa.h"


Trawa::Trawa(Punkt polozenie, Swiat* swiat)
	:Roslina(0, 0, 'T', 0, true, Organizmy::trawa, polozenie, swiat) {
	this->sila = 0;
	this->inicjatywa = 0;
	this->znak = 'T';
	this->wiek = 0;
}
string Trawa::getNazwaOrganizmu() {
	return "Trawa";
}
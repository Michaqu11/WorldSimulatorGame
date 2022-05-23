#include "Owca.h"

Owca::Owca(Punkt polozenie, Swiat* swiat)
	:Zwierze(4, 4, 'O', 0, true, Organizmy::owca, polozenie, swiat) {
	this->sila = 4;
	this->inicjatywa = 4;
	this->znak = 'O';
	this->wiek = 0;
}
string Owca::getNazwaOrganizmu() {
	return "Owca";
}
#include "CyberOwca.h"

CyberOwca::CyberOwca(Punkt polozenie, Swiat* swiat)
	:Zwierze(11, 4, 'C', 0, true, Organizmy::cyberOwca, polozenie, swiat) {
	this->sila = 11;
	this->inicjatywa = 4;
	this->znak = 'C';
	this->wiek = 0;
}
void CyberOwca::getNazwaOrganizmu() {
	cout << "CyberOwca" << endl;
}
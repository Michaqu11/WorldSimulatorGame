#include "Guarana.h"

Guarana::Guarana(Punkt polozenie, Swiat* swiat)
	:Roslina(0, 0, 'G', 0, true, Organizmy::guarana, polozenie, swiat) {
	this->sila = 0;
	this->inicjatywa = 0;
	this->znak = 'G';
	this->wiek = 0;
}
string Guarana::getNazwaOrganizmu() {
	return "Guarana";
}
void Guarana::kolizja(Organizm* other, bool atakujacy, bool* ruch) {
	zabojczeInformacjeDlaRoslin(other);
	//std::cout << other->getNazwaOrganizmu() << " z sila: " << other->getSila() << " zjadl -> " << this->getNazwaOrganizmu() << " z sila: " << this->getSila() << std::endl;
	other->setSila(other->getSila() + 3);
	swiat->wyczyscOrganizmZMapy(this->getPolozenie());
}
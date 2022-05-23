#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Punkt polozenie, Swiat* swiat)
	:Roslina(99, 0, 'J', 0, true, Organizmy::wilczeJagody, polozenie, swiat) {
	this->sila = 99;
	this->inicjatywa = 0;
	this->znak = 'J';
	this->wiek = 0;
}
string WilczeJagody::getNazwaOrganizmu() {
	return "Wilcze Jagody";
}
void WilczeJagody::kolizja(Organizm* other, bool atakujacy, bool* ruch) {

	if (this->getSila() > other->getSila() || (this->getSila() == other->getSila() && atakujacy)) {
		int tmp = this->sila;
		this->setSila(other->getSila() + 10);
		other->kolizja(this, false, ruch);
		this->setSila(tmp);
	}
	else {
		zabojczeInformacjeDlaRoslin(other);
		//std::cout << other->getZnak() << " z sila: " << other->getSila() << " zjadl -> " << this->getZnak() << " z sila: " << this->getSila() << std::endl;
		swiat->wyczyscOrganizmZMapy(this->polozenie);
		//swiat->ZabijOrganizm(other);
		//other->kolizja(this, false);
	}
}

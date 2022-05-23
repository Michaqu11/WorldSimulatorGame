#pragma once
#include "Roslina.h"
class Guarana :public Roslina
{
private:
	int sila;
	int inicjatywa;
	char znak;
public:
	void kolizja(Organizm* other, bool atakujacy, bool* ruch)  override;
	string getNazwaOrganizmu() override;
	Guarana(Punkt polozenie, Swiat* swiat);
};



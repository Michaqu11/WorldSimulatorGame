#pragma once//WilczeJagody
#include "Roslina.h"
class WilczeJagody :public Roslina
{
private:
	int sila;
	int inicjatywa;
	char znak;
public:
	void kolizja(Organizm* other, bool atakujacy, bool* ruch)  override;
	string getNazwaOrganizmu() override;
	WilczeJagody(Punkt polozenie, Swiat* swiat);
};


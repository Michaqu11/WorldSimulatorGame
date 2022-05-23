#pragma once
#include "Zwierze.h"
class Zolw :public Zwierze
{
private:
	int sila;
	int inicjatywa;
	char znak;
public:
	void akcja() override;
	void kolizja(Organizm* other, bool atakujacy, bool* ruch)  override;
	string getNazwaOrganizmu() override;
	Punkt losujPunktDlaZolwia();
	Zolw(Punkt polozenie, Swiat* swiat);
};

#pragma once
#include "Zwierze.h"
class Antylopa :public Zwierze
{
private:
	int sila;
	int inicjatywa;
	char znak;
public:
	Antylopa(Punkt polozenie, Swiat* swiat);
	void akcja() override;
	void kolizja(Organizm* other, bool atakujacy, bool* ruch)  override;
	string getNazwaOrganizmu() override;
	Punkt losujPunktDlaAntylopy();
	Punkt znajdzWolnyPunktDlaAntylopy();
};



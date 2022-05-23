#pragma once
#include "Zwierze.h"
class Czlowiek :public Zwierze
{
private:
	int sila;
	int inicjatywa;
	char znak;
	int ileOdejmowac;
public:
	Czlowiek(Punkt polozenie, Swiat* swiat);
	void akcja()  override;
	void kolizja(Organizm* other, bool atakujacy, bool* ruch)  override;
	string getNazwaOrganizmu() override;
	void rysowanie() override;
};


#pragma once
#include "Roslina.h"

class BarszczSosnowskiego :public Roslina
{
private:
	int sila;
	int inicjatywa;
	char znak;
public:
	void akcja() override;
	void kolizja(Organizm* other, bool atakujacy, bool* ruch)  override;
	string getNazwaOrganizmu() override;
	void zabijSasiednieOrganizmy(Punkt p);
	BarszczSosnowskiego(Punkt polozenie, Swiat* swiat);
};


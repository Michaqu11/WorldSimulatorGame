#pragma once
#include "Zwierze.h"
class Lis :public Zwierze
{
private:
	int sila;
	int inicjatywa;
	char znak;
public:
	Lis(Punkt polozenie, Swiat* swiat);
	void akcja() override;
	string getNazwaOrganizmu() override;
	Punkt losujPunktDlaLisa();
};


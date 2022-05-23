#pragma once
#include "Zwierze.h"
class Wilk:public Zwierze
{
private:
	int sila;
	int inicjatywa;
	char znak;
public:
	string getNazwaOrganizmu() override;
	Wilk(Punkt polozenie, Swiat* swiat);
};


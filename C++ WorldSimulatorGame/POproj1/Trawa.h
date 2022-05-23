#pragma once
#include "Roslina.h"
class Trawa :public Roslina
{
private:
	int sila;
	int inicjatywa;
	char znak;
public:
	string getNazwaOrganizmu() override;
	Trawa(Punkt polozenie, Swiat* swiat);
};


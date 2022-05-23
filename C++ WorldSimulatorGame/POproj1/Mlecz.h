#pragma once
#include "Roslina.h"
class Mlecz :public Roslina
{
private:
	int sila;
	int inicjatywa;
	char znak;
public:
	void akcja() override;
	string getNazwaOrganizmu() override;
	Mlecz(Punkt polozenie, Swiat* swiat);
};


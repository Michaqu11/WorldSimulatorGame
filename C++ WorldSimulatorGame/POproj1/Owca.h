#pragma once
#include "Zwierze.h"
class Owca :public Zwierze
{
private:
	int sila;
	int inicjatywa;
	char znak;
public:
	string getNazwaOrganizmu() override;
	Owca(Punkt polozenie, Swiat* swiat);
};
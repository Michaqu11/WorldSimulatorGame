#pragma once
#include "Zwierze.h"
class CyberOwca :public Zwierze
{
private:
	int sila;
	int inicjatywa;
	char znak;
public:
	CyberOwca(Punkt polozenie, Swiat* swiat);
	void getNazwaOrganizmu();
};
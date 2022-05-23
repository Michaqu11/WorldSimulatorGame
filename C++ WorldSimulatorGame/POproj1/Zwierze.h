#pragma once
#include <iostream>
#include "Organizm.h"
class Zwierze : public Organizm
{
public:
	Zwierze(int sila, int inicjatywa, char znak, int wiek, bool zycie, Organizmy organizm, Punkt polozenie, Swiat* swiat);
	virtual void akcja()  override;
	virtual void kolizja(Organizm* other, bool atakujacy, bool *ruch)  override;
	virtual void rysowanie() override;
	virtual ~Zwierze();
	Punkt wylosujPunktObok();
	Punkt znajdzWolnyPunktObok(Punkt p);
	void Move(Punkt p);
	void Rozmnazanie();

};


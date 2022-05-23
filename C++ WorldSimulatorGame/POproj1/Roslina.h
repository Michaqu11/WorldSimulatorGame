#pragma once
#include <iostream>
#include "Organizm.h"
class Roslina : public Organizm {
public:
	Roslina(int sila, int inicjatywa, char znak,int wiek, bool zycie, Organizmy organizm, Punkt polozenie, Swiat* swiat);
	virtual void akcja()  override;
	virtual void kolizja(Organizm* other, bool atakujacy, bool* ruch)  override;
	virtual ~Roslina();
	void Rozprzestrzenianie();
	Punkt znajdzWolnyPunktObok(Punkt p);
};


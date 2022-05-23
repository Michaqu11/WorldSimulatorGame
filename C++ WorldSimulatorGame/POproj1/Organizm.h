#pragma once
#include <iostream>
#include <string>
#include "Swiat.h"
#include "Punkt.h"

using namespace std;

class Swiat;
class Punkt;


class Organizm {
public:
	enum class Organizmy
	{
		czlowiek,
		wilk,
		owca,
		lis,
		zolw,
		antylopa,
		cyberOwca,
		trawa,
		mlecz,
		guarana,
		wilczeJagody,
		barszczSosnowskiego
	};

	Organizm(int sila, int inicjatywa, char znak, int wiek,  bool zycie, Organizmy organizm, Punkt polozenie, Swiat* swiat);

	int getSila();
	int getInicjatywa();
	int getWiek();
	char getZnak();
	bool getZycie();
	Organizmy getRodzajOrganizmu();
	Punkt getPolozenie();
	Swiat* getSwiat();

	void setSila(int sila);
	void setInicjatywa(int inicjatywa);
	void setZnak(char znak);
	void setWiek(int wiek);
	void setZycie(bool zycie);
	void setRodzajOrganizmu(Organizmy organizm);
	void setPolozenie(int x, int y);
	void setSwiat(Swiat* swiat);

	virtual void akcja() = 0;
	virtual void kolizja(Organizm* other, bool atakujacy, bool *ruch) = 0;
	virtual string getNazwaOrganizmu() = 0;
	virtual void rysowanie();
	void ogolneInformacje();
	void zabojczeInformacjeDlaZwierzat(Organizm* other);
	void zabojczeInformacjeDlaRoslin(Organizm* other);
	~Organizm();

protected:
	int sila;
	int inicjatywa;
	char znak;
	int wiek;
	bool zycie;
	Punkt polozenie;
	Swiat* swiat;
	Organizmy organizm;
};


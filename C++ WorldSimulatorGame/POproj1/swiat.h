#pragma once
#include <iostream>
#include <vector>
#include "Organizm.h"
#include "Punkt.h"
#include "Informator.h"

using namespace std;

class Organizm;

class Swiat
{
protected:
	int width;
	int height;
	int iloscZwierzat;
	int liczbaTur;
	Organizm*** mapaSwiata;
	vector<Organizm*> wszystkieOrganizmy;
	Punkt punktCzlowieka;
	Punkt nastepnyPunktCzlowieka;
	bool czyCzlowiekZyje;
	bool koniec;
	bool czySuperMocZostalaAktywowana;
	int iloscTurDoSuperMocy;
	string stringSwiat;
	string poprzedniaRunda;
public:
	Informator info;
	Swiat();
	Swiat(int width, int height, int iloscZwierzat);
	int getWidth();
	int getHeight();
	void setWidth(int width);
	void setHeight(int height);
	void setiloscZwierzat(int iloscZwierzat);
	void setLiczbaTur(int liczbaTur);
	void setiloscTurDoSuperMocy(int iloscTurDoSuperMocy);
	int getIloscTurDoSuperMocy();
	bool getCzySuperMocZostalaAktywowana();
	void setCzySuperMocZostalaAktywowana(bool superMoc);
	Organizm*** getMapaSwiata();
	vector<Organizm*> getWszystkieOrganizmy();
	void setNastepnyPunktCzlowieka(Punkt p);
	Punkt getNastepnyPunktCzlowieka();
	void setPunktCzlowieka(Punkt p);
	void setZycieCzlowieka(bool zycie);
	bool getZycieCzlowieka();
	void setKoniec(bool koniec);
	bool getKoniec();
	void stworzSwiat();
	bool czyZwierze(int x, int y);
	bool czyZwierzeZeZnaku(char znak);
	Organizm* stworzOrganizm(Punkt p);
	void stworzRosline(Punkt p, char znak);
	bool czyPustePole(int x, int y);
	void stworzZwierze(Punkt p, char znak);
	void rysujSwiat();
	void rysujKoniecGry();
	void wykonajTure();
	void klawisze();
	void sortujOrganizmy();
	void wyczyscOrganizmZMapy(Punkt p);
	void ZabijOrganizm(Organizm* organizm, int index);
	void Ruch(Organizm* organizm, Punkt p);
	Punkt wylosujPunkt();
	void zapiszSwiat();
	void wczytajSwiat();
	~Swiat();
};



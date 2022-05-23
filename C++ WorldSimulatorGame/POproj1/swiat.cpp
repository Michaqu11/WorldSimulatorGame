#include "Swiat.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <conio.h>
#include <algorithm>
#include <tuple>
#include <fstream>

#include "Informator.h"
#include "Czlowiek.h"
#include "Organizm.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"

using namespace std;

#define ILOSC_ORGANIZMOW 10


Swiat::Swiat() {
	this->width = 20;
	this->height = 20;
	this->iloscZwierzat = 10;
	this->liczbaTur = 0;
	this->czyCzlowiekZyje = true;
	this->iloscTurDoSuperMocy = 0;
	this->czySuperMocZostalaAktywowana = false;
	this->koniec = false;
	this->stringSwiat = "";
	this->poprzedniaRunda = "";
	mapaSwiata = new Organizm * *[height];
	for (int i = 0; i < height; i++) {
		mapaSwiata[i] = new Organizm * [width];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			mapaSwiata[i][j] = nullptr;
		}
	}
}
Swiat::Swiat(int width, int height, int iloscZwierzat) {
	this->width = width;
	this->height = height;
	this->iloscZwierzat = iloscZwierzat;
	this->liczbaTur = 0;
	this->czyCzlowiekZyje = true;
	this->iloscTurDoSuperMocy = 0;
	this->czySuperMocZostalaAktywowana = false;
	this->koniec = false;
	this->stringSwiat = "";
	this->poprzedniaRunda = "";

	mapaSwiata = new Organizm * *[height];
	for (int i = 0; i < height; i++) {
		mapaSwiata[i] = new Organizm * [width];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			mapaSwiata[i][j] = nullptr;
		}
	}
}

void Swiat::setNastepnyPunktCzlowieka(Punkt p) {
	this->nastepnyPunktCzlowieka = p;
}
Punkt Swiat::getNastepnyPunktCzlowieka() {
	return nastepnyPunktCzlowieka;
}
void Swiat::setPunktCzlowieka(Punkt p) {
	this->punktCzlowieka = p;
}

vector<Organizm*> Swiat::getWszystkieOrganizmy() {
	return wszystkieOrganizmy;
}

int Swiat::getWidth() {
	return width;
}
int Swiat::getHeight() {
	return height;
}
void Swiat::setWidth(int width) {
	this->width = width;
}
void Swiat::setHeight(int height) {
	this->height = height;
}
void Swiat::setiloscZwierzat(int iloscZwierzat) {
	this->iloscZwierzat = iloscZwierzat;
}
void Swiat::setLiczbaTur(int liczbaTur) {
	this->liczbaTur = liczbaTur;
}
void Swiat::setiloscTurDoSuperMocy(int iloscTurDoSuperMocy) {
	this->iloscTurDoSuperMocy = iloscTurDoSuperMocy;
}
int Swiat::getIloscTurDoSuperMocy() {
	return iloscTurDoSuperMocy;
}
bool Swiat::getCzySuperMocZostalaAktywowana() {
	return czySuperMocZostalaAktywowana;
}
void Swiat::setCzySuperMocZostalaAktywowana(bool superMoc) {
	this->czySuperMocZostalaAktywowana = superMoc;
}
Organizm*** Swiat::getMapaSwiata() {
	return mapaSwiata;
}

Organizm* Swiat::stworzOrganizm(Punkt p) {
	int x = rand() % ILOSC_ORGANIZMOW;
	Organizm* organizm;
	if (x == 0) {
		organizm = new Wilk(p, this);
	}
	else if (x == 1) {
		organizm = new Owca(p, this);
	}
	else if (x == 2) {
		organizm = new Lis(p, this);
	}
	else if (x == 3) {
		organizm = new Zolw(p, this);
	}
	else if (x == 4) {
		organizm = new Antylopa(p, this);
	}
	else if (x == 5) {
		organizm = new Trawa(p, this);
	}
	else if (x == 6) {
		organizm = new Mlecz(p, this);
	}
	else if (x == 7) {
		organizm = new Guarana(p, this);
	}
	else if (x == 8) {
		organizm = new WilczeJagody(p, this);
	}
	else {
		organizm = new BarszczSosnowskiego(p, this);
	}
	wszystkieOrganizmy.push_back(organizm);
	return organizm;
}

void Swiat::stworzRosline(Punkt p, char znak) {

	Organizm* organizm;

	if (znak == 'T') {
		organizm = new Trawa(p, this);
	}
	else if (znak == 'M') {
		organizm = new Mlecz(p, this);
	}
	else if (znak == 'G') {
		organizm = new Guarana(p, this);
	}
	else if (znak == 'J') {
		organizm = new WilczeJagody(p, this);
	}
	else {
		organizm = new BarszczSosnowskiego(p, this);
	}
	wszystkieOrganizmy.push_back(organizm);
	mapaSwiata[p.getY()][p.getX()] = organizm;

}
void Swiat::stworzZwierze(Punkt p, char znak) {

	Organizm* organizm;
	if (znak == 'C') {
		organizm = new Czlowiek(p, this);
	}
	else if (znak == 'W') {
		organizm = new Wilk(p, this);
	}
	else if (znak == 'O') {
		organizm = new Owca(p, this);
	}
	else if (znak == 'L') {
		organizm = new Lis(p, this);
	}
	else if (znak == 'Z') {
		organizm = new Zolw(p, this);
	}
	else {
		organizm = new Antylopa(p, this);
	}

	wszystkieOrganizmy.push_back(organizm);
	mapaSwiata[p.getY()][p.getX()] = organizm;

}
void Swiat::stworzSwiat() {

	Punkt p = wylosujPunkt();
	Organizm* organizm = new Czlowiek(p, this);
	this->punktCzlowieka = p;
	wszystkieOrganizmy.push_back(organizm);
	mapaSwiata[p.getY()][p.getX()] = organizm;

	for (int i = 0; i < iloscZwierzat - 1; i++) {
		Punkt p = wylosujPunkt();
		Organizm* organizm = stworzOrganizm(p);
		mapaSwiata[p.getY()][p.getX()] = organizm;
	}
}

void Swiat::setZycieCzlowieka(bool zycie) {
	this->czyCzlowiekZyje = zycie;
}
bool Swiat::getZycieCzlowieka() {
	return czyCzlowiekZyje;
}
void Swiat::setKoniec(bool koniec) {
	this->koniec = koniec;
}
bool Swiat::getKoniec() {
	return koniec;
}

void Swiat::klawisze() {

	if (this->czyCzlowiekZyje) {
		cout << endl << "# INSTRUKCJA: 1) strzalki - ruch czlowiekiem, 2) p - super moc czlowieka, 3) i - informacje z poprzedniej rundy, 4) esc - koniec gry #" << endl;
		Punkt p = this->punktCzlowieka;
		Punkt p2;
		bool e = false;
		if (iloscTurDoSuperMocy != 0) {
			iloscTurDoSuperMocy--;
		}
		while (!e)
		{
			char znak = _getch();
			switch (znak) {
			case 72: // gora
				if (p.getY() != 0) {
					p2.setY(p.getY() - 1);
					p2.setX(p.getX());
					e = true;
				}
				else {
					cout << " Nie mozesz isc wyzej! " << endl;
				}
				break;
			case 80: // dol
				if (p.getY() != height - 1) {
					p2.setY(p.getY() + 1);
					p2.setX(p.getX());
					e = true;
				}
				else {
					cout << " Nie mozesz isc nizej! " << endl;
				}
				break;
			case 77: // prawo
				if (p.getX() != width - 1) {
					p2.setY(p.getY());
					p2.setX(p.getX() + 1);
					e = true;
				}
				else {
					cout << " Nie mozesz isc bardziej w prawo! " << endl;
				}
				break;
			case 75: // left
				if (p.getX() != 0) {
					p2.setY(p.getY());
					p2.setX(p.getX() - 1);
					e = true;
				}
				else {
					cout << " Nie mozesz isc bardziej w lewo! " << endl;
				}
				break;
			case 105:
				if (liczbaTur != 0) {
					system("CLS");
					if (poprzedniaRunda == "") {
						cout << "# Po wczytaniu mapy, nie zapisuja sie informacje z poprzedniej rudny! Musisz zagrac kolejna runde, aby uzyskac jakies informacje! #" << endl;
					}
					else {
						cout << endl << poprzedniaRunda << endl;
						info.wypiszInfoirmacje();
					}
					rysujSwiat();
					cout << endl << "# INSTRUKCJA: 1) strzalki - ruch czlowiekiem, 2) p - super moc czlowieka, 3) i - informacje z poprzedniej rundy, 4) esc - koniec gry #" << endl;
				}
				else {
					cout << " Nie bylo jeszcze zadnej tury " << endl;
				}
				break;
			case 112: // p
				if (iloscTurDoSuperMocy == 0) {
					cout << " Moc zostanie aktywowana! " << endl;
					this->czySuperMocZostalaAktywowana = true;
					this->iloscTurDoSuperMocy = 5;
				}
				else {
					cout << " Zostalo jeszcze " << getIloscTurDoSuperMocy() << " tur do aktywowania mocy czlowieka " << endl;
				}
				break;

			case 27: // esc
				e = true;
				this->koniec = true;
				break;
			}
		}
		nastepnyPunktCzlowieka = p2;
	}
	else {
		cout << "# CZLOWIEK NIE ZYJE! Nie mozesz juz nim sterowac :c #" << endl;
		cout << endl << "# INSTRUKCJA: 1) strzalka w prawo - kolejna runda, 2) i - informacje z poprzedniej rundy, 3) esc - koniec gry #" << endl;
		bool e = false;
		while (!e) {
			char znak = _getch();
			switch (znak) {
			case 77: // prawo
				e = true;
				break;
			case 105:
				system("CLS");
				if (poprzedniaRunda == "") {
					cout << "# Po wczytaniu mapy, nie zapisuja sie informacje z poprzedniej rudny! Musisz zagrac kolejna runde, aby uzyskac jakies informacje! #" << endl;
				}
				else {
					cout << endl << poprzedniaRunda << endl;
					info.wypiszInfoirmacje();
				}
				rysujSwiat();
				cout << endl << "# INSTRUKCJA: 1) strzalka w prawo - kolejna runda, 2) i - informacje z poprzedniej rundy, 3) esc - koniec gry #" << endl;
				break;
			case 27: // esc
				e = true;
				this->koniec = true;
				break;
			}
		}
	}
}

void Swiat::sortujOrganizmy() {

	sort(wszystkieOrganizmy.begin(), wszystkieOrganizmy.end(),
		[](Organizm* organizm1, Organizm* organizm2) {
			int inicjatywa1 = organizm1->getInicjatywa();
			int inicjatywa2 = organizm2->getInicjatywa();
			int wiek1 = organizm1->getWiek();
			int wiek2 = organizm2->getWiek();
			return tie(inicjatywa2, wiek1) < tie(inicjatywa1, wiek2);
		});
}
void Swiat::wykonajTure() {
	cout << "Zrob ruch: " << endl;
	klawisze();

	info.usunInformacje();

	if (!koniec) {

		sortujOrganizmy();
		int rozmiar = wszystkieOrganizmy.size();
		bool czyKtosZmarl = false;
		for (size_t i = 0; i < rozmiar; i++) {
			if (wszystkieOrganizmy[i]->getZycie()) {
				wszystkieOrganizmy[i]->akcja();
			}
			else {
				czyKtosZmarl = true;
			}
		}
		if (czyKtosZmarl) {
			info.dodajInfocjmacje("\nCmentarz: \n");
		}
		for (size_t i = 0; i < wszystkieOrganizmy.size(); i++) {
			if (!wszystkieOrganizmy[i]->getZycie()) {
				ZabijOrganizm(wszystkieOrganizmy[i], i);
			}
		}
	}
	liczbaTur++;
}
void Swiat::rysujSwiat() {
	poprzedniaRunda = stringSwiat;
	stringSwiat = "\n    #  POPRZEDNIA RUNDA:  #\n";
	cout << endl;
	cout << "   # Numer tury: " << this->liczbaTur << " #" << endl;
	cout << "   # ilosc organizmow: " << wszystkieOrganizmy.size() << " #" << endl;
	cout << endl;
	cout << "       ";
	stringSwiat += "\n    # Numer tury: " + to_string(this->liczbaTur) + " #\n" + "    # ilosc organizmow: " + to_string(wszystkieOrganizmy.size()) + " #\n\n       ";
	for (int i = 0; i < width + 2; i++) {
		cout << "#";
		stringSwiat += "#";
	}
	cout << endl;
	stringSwiat += "\n";
	for (int i = 0; i < height; i++) {
		cout << "       #";
		stringSwiat += "       #";
		for (int j = 0; j < width; j++) {
			if (mapaSwiata[i][j] == nullptr) {
				cout << "_";
				stringSwiat += "_";
			}
			else {
				stringSwiat += mapaSwiata[i][j]->getZnak();
				mapaSwiata[i][j]->rysowanie();
			}
		}
		stringSwiat += "#\n";
		cout << "#";
		cout << endl;
	}
	stringSwiat += "       ";
	cout << "       ";
	for (int i = 0; i < width + 2; i++) {
		cout << "#";
		stringSwiat += "#";
	}
	stringSwiat += "\n\n";
	cout << endl;
	cout << endl;
}

void Swiat::rysujKoniecGry() {
	cout << endl;
	cout << endl;
	cout << " XXXXX  X   X  XXXX    XXXX  X    X  XXXX     X" << endl;
	cout << "   X    X   X  X       X     XX   X  X   X    X" << endl;
	cout << "   X    XXXXX  XXXX    XXXX  X X  X  X   X    X" << endl;
	cout << "   X    X   X  X       X     X   XX  X   X     " << endl;
	cout << "   X    X   X  XXXX    XXXX  X    X  XXXX     X" << endl;
}

Punkt Swiat::wylosujPunkt() {
	int x, y;
	while (true) {
		x = rand() % width;
		y = rand() % height;
		if (mapaSwiata[y][x] == nullptr) {
			break;
		}
	}
	return Punkt(x, y);
}

void Swiat::wyczyscOrganizmZMapy(Punkt p) {

	mapaSwiata[p.getY()][p.getX()]->setZycie(false);
	mapaSwiata[p.getY()][p.getX()] = nullptr;
}
void Swiat::ZabijOrganizm(Organizm* organizm, int index) {
	info.dodajInfocjmacje(" Mordowanie " + organizm->getNazwaOrganizmu() + " z pola " + to_string(organizm->getPolozenie().getX()) + " " + to_string(organizm->getPolozenie().getY()) + "\n");
	//cout << " Mordowanie "<< organizm->getZnak() << " z miejsca " << organizm->getPolozenie().getX() << " " << organizm->getPolozenie().getY() << endl;
	delete organizm;
	wszystkieOrganizmy.erase(wszystkieOrganizmy.begin() + index);
	//remove(wszystkieOrganizmy.begin(), wszystkieOrganizmy.end(), organizm);
}
bool Swiat::czyZwierze(int x, int y) {
	if (mapaSwiata[y][x]->getZnak() == 'W' || mapaSwiata[y][x]->getZnak() == 'O' || mapaSwiata[y][x]->getZnak() == 'L'
		|| mapaSwiata[y][x]->getZnak() == 'Z' || mapaSwiata[y][x]->getZnak() == 'A' || mapaSwiata[y][x]->getZnak() == 'C') {
		return true;
	}
	return false;
}
bool Swiat::czyPustePole(int x, int y) {
	if (mapaSwiata[y][x] == nullptr) {
		return true;
	}
	return false;
}

void Swiat::Ruch(Organizm* organizm, Punkt p) {
	//std::cout << " 4) " << p.getX() << " " << p.getY() << std::endl;
	mapaSwiata[organizm->getPolozenie().getY()][organizm->getPolozenie().getY()] = nullptr;
	mapaSwiata[p.getY()][p.getX()] = organizm;
	organizm->getPolozenie().setX(p.getX());
	organizm->getPolozenie().setY(p.getY());
}

bool Swiat::czyZwierzeZeZnaku(char znak) {
	if (znak == 'W' || znak == 'O' || znak == 'L' || znak == 'Z' || znak == 'A' || znak == 'C') {
		return true;
	}
	return false;
}


void Swiat::zapiszSwiat() {

	std::ofstream zapisz("swiat.txt", std::ofstream::out); // szerkosc wysokosc liczbaTur iloscOrganizmow -> znak sila wiek polozenie(x,y)
	zapisz << width << " " << height << " " << liczbaTur - 1 << " " << wszystkieOrganizmy.size() << " " << iloscTurDoSuperMocy;
	zapisz << '\n';
	for (int i = 0; i < wszystkieOrganizmy.size(); i++) {
		zapisz << wszystkieOrganizmy[i]->getZnak() << " " << wszystkieOrganizmy[i]->getSila() << " " << wszystkieOrganizmy[i]->getWiek() << " " << wszystkieOrganizmy[i]->getPolozenie().getX() << " " << wszystkieOrganizmy[i]->getPolozenie().getY();
		zapisz << '\n';
	}

	zapisz.close();
}

void Swiat::wczytajSwiat() {
	ifstream wczytaj("swiat.txt"); // znak sila wiek x y
	int iloscOrganizmow, szerokosc, wysokosc, liczbaTur, iloscTurDoSuperMocy, sila, wiek, x, y;
	char znak;
	wczytaj >> szerokosc >> wysokosc >> liczbaTur >> iloscOrganizmow >> iloscTurDoSuperMocy;
	this->setWidth(szerokosc);
	this->setHeight(wysokosc);
	this->setiloscZwierzat(iloscOrganizmow);
	this->setLiczbaTur(liczbaTur);
	this->setiloscTurDoSuperMocy(iloscTurDoSuperMocy);
	bool czyBylCzkiwiek = false;
	for (int i = 0; i < iloscOrganizmow; i++) {
		wczytaj >> znak >> sila >> wiek >> x >> y;
		Punkt p;
		p.setX(x);
		p.setY(y);
		if (czyZwierzeZeZnaku(znak)) {
			stworzZwierze(p, znak);
		}
		else {
			stworzRosline(p, znak);
		}
		mapaSwiata[y][x]->setSila(sila);
		mapaSwiata[y][x]->setWiek(wiek);
		if (znak == 'C') {
			this->punktCzlowieka = p;
			czyBylCzkiwiek = true;
		}
	}
	if (!czyBylCzkiwiek) {
		this->czyCzlowiekZyje = false;
	}
}

Swiat::~Swiat() {
	delete mapaSwiata;
}
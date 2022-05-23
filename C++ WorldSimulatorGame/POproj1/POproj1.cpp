#include <iostream>
#include <vector>
#include <ctime>
#include "Swiat.h"

using namespace std;

int main() {

	srand(time(NULL));
	string jakiSwiat;
	cout << " Czy chcesz stworzyc nowy swiat czy wczytac stary? (N - nowy, S - stary)" << endl;
	cin >> jakiSwiat;
	if (jakiSwiat == "N" || jakiSwiat == "n" || jakiSwiat == "Nowy" || jakiSwiat == "nowy") {
		int width, height, iloscZwierzat;
		cout << "Podaj rozmiar planszy: {" << endl;
		cout << "    Podaj szerokosc:" << endl;
		cin >> width;
		cout << "    Podaj wysokosc: " << endl;
		cin >> height;
		cout << "}" << endl;

		iloscZwierzat = width * height * 0.3;

		Swiat swiat(width, height, iloscZwierzat);
		swiat.stworzSwiat();
		swiat.rysujSwiat();
		while (!(swiat.getKoniec())) {
			swiat.wykonajTure();
			if (!(swiat.getKoniec())) {
				system("CLS");
				swiat.rysujSwiat();
			}
			else {
				swiat.rysujKoniecGry();
			}
		}
		string zapis;
		cout << endl << endl << endl;
		cout << " Czy chcesz zapisac swiat? " << endl;
		cin >> zapis;
		if (zapis == "T" || zapis == "t" || zapis == "Tak" || zapis == "tak") {
			swiat.zapiszSwiat();
		}
	}
	else if(jakiSwiat == "S" || jakiSwiat == "s" || jakiSwiat == "Stary" || jakiSwiat == "stary") {
		Swiat swiat;
		swiat.wczytajSwiat();
		swiat.rysujSwiat();
		while (!(swiat.getKoniec())) {
			swiat.wykonajTure();
			if (!(swiat.getKoniec())) {
				system("CLS");
				swiat.rysujSwiat();
			}
			else {
				swiat.rysujKoniecGry();
			}
		}
		string zapis;
		cout << endl << endl << endl;
		cout << " Czy chcesz zapisac swiat? " << endl;
		cin >> zapis;
		if (zapis == "T" || zapis == "t" || zapis == "Tak" || zapis == "tak") {
			swiat.zapiszSwiat();
		}
	}
}


#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(Punkt polozenie, Swiat* swiat)
	:Roslina(10, 0, 'B', 0, true, Organizmy::barszczSosnowskiego, polozenie, swiat) {
	this->sila = 10;
	this->inicjatywa = 0;
	this->znak = 'B';
	this->wiek = 0;
}

string BarszczSosnowskiego::getNazwaOrganizmu() {
	return "Barszcz Sosnowskiego";
}

void BarszczSosnowskiego::akcja() {
	this->wiek++;
	ogolneInformacje();
	//cout << this->getNazwaOrganizmu() << " ";
	//cout << " Z pola: " << this->polozenie.getX() << " " << this->polozenie.getY();

	int x = rand() % 20;
	if (x < 1) {
		//cout << " Rozprzestrzenia sie!" << endl;
		Rozprzestrzenianie();
	}
	else {
		swiat->info.dodajInfocjmacje(" Nie udalo sie rozprzestrzenic ");
		//cout << " Nie udalo sie rozprzestrzenic " << endl;
	}
	zabijSasiednieOrganizmy(this->polozenie);

	swiat->info.dodajInfocjmacje("\n");
}

void BarszczSosnowskiego::kolizja(Organizm* other, bool atakujacy, bool* ruch) {


	
	if (this->getSila() > other->getSila() || (this->getSila() == other->getSila() && atakujacy)) {
		int tmp = this->sila;
		this->setSila(other->getSila() + 10);
		other->kolizja(this, false, ruch);
		this->setSila(tmp);
	}
	else {
		zabojczeInformacjeDlaRoslin(other);
		//std::cout << other->getZnak() << " z sila: " << other->getSila() << " zjadl -> " << this->getZnak() << " z sila: " << this->getSila() << std::endl;
		swiat->wyczyscOrganizmZMapy(this->polozenie);
		//swiat->ZabijOrganizm(other);
		//other->kolizja(this, false);
	}
}

void BarszczSosnowskiego::zabijSasiednieOrganizmy(Punkt p) {

	if (p.getY() != 0 && !(swiat->czyPustePole(p.getX(), p.getY() - 1)) && swiat->czyZwierze(p.getX(), p.getY() - 1)) {
		swiat->info.dodajInfocjmacje(" zabija -> " + swiat->getMapaSwiata()[p.getY() - 1][p.getX()]->getNazwaOrganizmu() + " z pola " + to_string(p.getX()) + " " + to_string(p.getY() - 1));
		//cout << "Zabija -> " << swiat->getMapaSwiata()[p.getY() - 1][p.getX()]->getZnak() << " z pola " << p.getX() << " " << p.getY() - 1 << endl;
		if (swiat->getMapaSwiata()[p.getY() - 1][p.getX()]->getZnak() == 'C') {
			swiat->setZycieCzlowieka(false);
		}
		swiat->getMapaSwiata()[p.getY() - 1][p.getX()]->setZycie(false);
		swiat->getMapaSwiata()[p.getY() - 1][p.getX()] = nullptr;
	}
	if (p.getY() != swiat->getHeight() - 1 && !(swiat->czyPustePole(p.getX(), p.getY() + 1)) && swiat->czyZwierze(p.getX(), p.getY() + 1)) {
		swiat->info.dodajInfocjmacje(" zabija -> " + swiat->getMapaSwiata()[p.getY() + 1][p.getX()]->getNazwaOrganizmu() + " z pola " + to_string(p.getX()) + " " + to_string(p.getY() + 1));
		//cout << "Zabija -> " << swiat->getMapaSwiata()[p.getY() + 1][p.getX()]->getZnak() << " z pola " << p.getX() << " " << p.getY() + 1 << endl;
		if (swiat->getMapaSwiata()[p.getY() + 1][p.getX()]->getZnak() == 'C') {
			swiat->setZycieCzlowieka(false);
		}
		swiat->getMapaSwiata()[p.getY() + 1][p.getX()]->setZycie(false);
		swiat->getMapaSwiata()[p.getY() + 1][p.getX()] = nullptr;
	}
	if (p.getX() != 0 && !(swiat->czyPustePole(p.getX() - 1, p.getY())) && swiat->czyZwierze(p.getX() - 1, p.getY())) {
		swiat->info.dodajInfocjmacje(" zabija -> " + swiat->getMapaSwiata()[p.getY()][p.getX() - 1]->getNazwaOrganizmu() +" z pola " + to_string(p.getX() - 1) + " " + to_string(p.getY()));
		//cout << "Zabija -> " << swiat->getMapaSwiata()[p.getY()][p.getX() - 1]->getZnak() << " z pola " << p.getX() - 1 << " " << p.getY() << endl;
		if (swiat->getMapaSwiata()[p.getY()][p.getX() - 1]->getZnak() == 'C') {
			swiat->setZycieCzlowieka(false);
		}
		swiat->getMapaSwiata()[p.getY()][p.getX() - 1]->setZycie(false);
		swiat->getMapaSwiata()[p.getY()][p.getX() - 1] = nullptr;
	}
	if (p.getX() != swiat->getWidth() - 1 && !(swiat->czyPustePole(p.getX() + 1, p.getY())) && swiat->czyZwierze(p.getX() + 1, p.getY())) {
		swiat->info.dodajInfocjmacje(" zabija -> " + swiat->getMapaSwiata()[p.getY()][p.getX() + 1]->getNazwaOrganizmu()+" z pola " + to_string(p.getX() + 1) + " " + to_string(p.getY()));
		//cout << "Zabija -> " << swiat->getMapaSwiata()[p.getY()][p.getX() + 1]->getZnak() << " z pola " << p.getX() + 1 << " " << p.getY() << endl;
		if (swiat->getMapaSwiata()[p.getY()][p.getX() + 1]->getZnak() == 'C') {
			swiat->setZycieCzlowieka(false);
		}
		swiat->getMapaSwiata()[p.getY()][p.getX() + 1]->setZycie(false);
		swiat->getMapaSwiata()[p.getY()][p.getX() + 1] = nullptr;
	}
}

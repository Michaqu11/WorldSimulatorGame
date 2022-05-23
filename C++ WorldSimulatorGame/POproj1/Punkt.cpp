#include "Punkt.h"

Punkt::Punkt() {
	this->x = 0;
	this->y = 0;
}

Punkt::Punkt(int x, int y) {
	this->x = x;
	this->y = y;
}

int Punkt::getX() {
	return x;
}
int Punkt::getY() {
	return y;
}
void Punkt::setX(int x) {
	this->x = x;
}
void Punkt::setY(int y) {
	this->y = y;
}

bool Punkt::operator==(const Punkt& other) {
	return (x == other.x && y == other.y);
}
bool Punkt::operator!=(const Punkt& other) {
	return (!(x == other.x && y == other.y));
}
Punkt& Punkt::operator=(const Punkt& right) { // kopiujacy operator przypisania
	this->x = right.x;
	this->y = right.y;
	return *this;
}

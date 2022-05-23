#pragma once
#include <iostream>

class Punkt
{
private:
	int x;
	int y;
public:
	Punkt();
	Punkt(int x, int y);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	bool  operator==(const Punkt& other);
	bool  operator!=(const Punkt& other);
	Punkt& operator=(const Punkt& other);
};


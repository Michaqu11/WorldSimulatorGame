#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Informator
{
private:
	vector<string> informacje;
public:
	void dodajInfocjmacje(string info);
	void wypiszInfoirmacje();
	void usunInformacje();
};


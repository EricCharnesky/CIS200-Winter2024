#pragma once

#include <string>

using namespace std;

class Weapon {
private:
	string name;
	double range;
	int maxDamage;
public:
	Weapon(string name, double range, int maxDamage) {
		this->name = name;
		this->range = range;
		this->maxDamage = maxDamage;
	}

	double getRange() {
		return this->range;
	}

	virtual int getDamage() {
		return rand() % maxDamage + 1;
	}

	string getName() {
		return name;
	}
};
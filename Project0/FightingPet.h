#pragma once

#include <string>

using namespace std;

class FightingPet {

private:
	string name;
	int number;
	int combatPower;

public:
	FightingPet() {
		name = "";
		number = 0;
		combatPower = 0;
	}

	FightingPet(string name, int number, int combatPower) {
		this->name = name;
		this->number = number;
		this->combatPower = combatPower;
	}

	void setName(string name) {
		this->name = name;
	}

	void setNumber(int number) {
		this->number = number;
	}

	void setCombatPower(int combatPower) {
		this->combatPower = combatPower;
	}

	string getName() {
		return name;
	}

	int getNumber() {
		return number;
	}

	int getCombatPower() {
		return combatPower;
	}
};
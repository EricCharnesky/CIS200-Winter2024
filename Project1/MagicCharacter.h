#pragma once

#include "Character.h"

class MagicCharacter : public Character {
private:
	int intelligence;

	static const int DISTANCE = 10;

	int getDamage() {
		return intelligence / 3;
	}
public:
	MagicCharacter(string name, int maxHitPoints, int currentHitPoints,
		int dexterity, int xLocation, int yLocation, Weapon* weapon, int intelligence) 
		: Character(name, maxHitPoints, currentHitPoints, dexterity, xLocation, yLocation, weapon ) {
		this->intelligence = intelligence;
	}

	void attack(Character* target) override {
		if (isAlive() && distanceToTarget(target) <= DISTANCE && attackRoll(target)) {
			target->takeDamage(getDamage());
		}
	}

	int getIntelligence() {
		return intelligence;
	}
};
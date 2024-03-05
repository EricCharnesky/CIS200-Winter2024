#pragma once

#include "Weapon.h"

class HealingStick : public Weapon {
private:

public:
	HealingStick(string name, double range, int maxDamage) : Weapon(name, range, maxDamage) {

	}

	int getDamage() override {
		return Weapon::getDamage() * -1;
	}
};
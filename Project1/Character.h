#pragma once

#include <string>
#include "Weapon.h"

using namespace std;

class Character {
private:
	string name;
	int maxHitPoints;
	int currentHitPoints;
	int dexterity;
	int xLocation;
	int yLocation;
	Weapon* weapon;

    bool isWithinRange(Character* target) {
        double range = sqrt(2);
        if (weapon != nullptr) {
            range = weapon->getRange();
        }
        
        return distanceToTarget(target) <= range;
    }

    int getDamage() {
        int damage = 1;
        if (weapon != nullptr) {
            damage = weapon->getDamage();
        }
        return damage;
    }

protected:
    double distanceToTarget(Character* target)
    {
        return sqrt(
            pow(xLocation - target->getXLocation(), 2) +
            pow(yLocation - target->getYLocation(), 2)
        );
    }


    bool attackRoll(Character* target)
    {
        return rand() % 20 + 1 > target->getDexterity();
    }

public:
	Character(string name, int maxHitPoints, int currentHitPoints, 
		int dexterity, int xLocation, int yLocation, Weapon* weapon) {
		this->name = name;
		this->maxHitPoints = maxHitPoints;
		this->currentHitPoints = currentHitPoints;
		this->dexterity = dexterity;
		setXLocation(xLocation);
        setYLocation(yLocation);
		setWeapon(weapon);
	}

    /* from umgpt promt :
    in c++, given a class with these attributes, write get methods for accessing all the attributes
        class Character {
        private:
            string name;
            int maxHitPoints;
            int currentHitPoints;
            int dexterity;
            int xLocation;
            int yLocation;
            Weapon* weapon;
    }
    */

    // Getter for the name attribute
    std::string getName() const {
        return name;
    }

    // Getter for the maxHitPoints attribute
    int getMaxHitPoints() const {
        return maxHitPoints;
    }

    // Getter for the currentHitPoints attribute
    int getCurrentHitPoints() const {
        return currentHitPoints;
    }

    // Getter for the dexterity attribute
    int getDexterity() const {
        return dexterity;
    }

    // Getter for the xLocation attribute
    int getXLocation() const {
        return xLocation;
    }

    // Getter for the yLocation attribute
    int getYLocation() const {
        return yLocation;
    }

    // Getter for the weapon attribute
    Weapon* getWeapon() const {
        return weapon;
    }

    /* umgpt prompt: add set functions for xLocation, yLocation, and weapon */

     // Setter for the xLocation attribute
    void setXLocation(int newXLocation) {
        xLocation = newXLocation;
    }

    // Setter for the yLocation attribute
    void setYLocation(int newYLocation) {
        yLocation = newYLocation;
    }

    // Setter for the weapon attribute
    void setWeapon(Weapon* newWeapon) {
        weapon = newWeapon;
    }

    virtual void attack(Character* target) {
        if (isAlive() && isWithinRange(target) && attackRoll(target)) {
            target->takeDamage(getDamage());
        }
    }

    bool isAlive()
    {
        return currentHitPoints > 0;
    }


    void takeDamage(int damage) {
        currentHitPoints -= damage;
        if (currentHitPoints < 0) {
            currentHitPoints = 0;
        }
        else if (currentHitPoints > maxHitPoints) {
            currentHitPoints = maxHitPoints;
        }
    }

};
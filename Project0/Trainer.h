#pragma once

#include "FightingPet.h"

class Trainer
{
private:
	string name;
	int level;
	int experiencePoints;
	int maxNumberOfFightingPets;
	FightingPet* pets;
	int numberOfFightingPets;

public:
	Trainer(string name, int level, int experiencePoints, int maxNumberOfFightingPets) {
		this->name = name;
		this->level = level;
		this->experiencePoints = experiencePoints;
		this->maxNumberOfFightingPets = maxNumberOfFightingPets;
		pets = new FightingPet[maxNumberOfFightingPets];
		numberOfFightingPets = 0;
	}

	Trainer(Trainer& const trainer) {
		this->name = trainer.name;
		this->level = trainer.level;
		this->experiencePoints = trainer.experiencePoints;
		this->maxNumberOfFightingPets = trainer.maxNumberOfFightingPets;
		this->numberOfFightingPets = trainer.numberOfFightingPets;
		pets = new FightingPet[maxNumberOfFightingPets];
		for (int index = 0; index < maxNumberOfFightingPets; index++) {
			pets[index] = trainer.pets[index];
		}
	}

	Trainer operator= (Trainer const trainer) {
		this->name = trainer.name;
		this->level = trainer.level;
		this->experiencePoints = trainer.experiencePoints;
		this->maxNumberOfFightingPets = trainer.maxNumberOfFightingPets;
		this->numberOfFightingPets = trainer.numberOfFightingPets;
		delete[] pets;
		pets = new FightingPet[maxNumberOfFightingPets];
		for (int index = 0; index < maxNumberOfFightingPets; index++) {
			pets[index] = trainer.pets[index];
		}
	}

	~Trainer() {
		delete[] pets;
	}

	FightingPet& getFightingPet(int index) {
		if (index >= numberOfFightingPets) {
			throw exception();
		}
		return pets[index];
	}

	void addExperiencePoints(int experiencePointsToAdd) {
		experiencePoints += experiencePointsToAdd;
		while (experiencePoints >= level * 1000) {
			experiencePoints -= level * 1000; // or set back to 0
			level++;
		}
	}

	void addFightingPet(FightingPet pet) {
		if (numberOfFightingPets == maxNumberOfFightingPets) {
			// TODO - use better exception type
			throw new exception();
		}
		pets[numberOfFightingPets] = pet;
		numberOfFightingPets++;
	}

	void addMoreFightingPetStorage() {
		FightingPet* newPets = new FightingPet[maxNumberOfFightingPets * 2];
		for (int index = 0; index < maxNumberOfFightingPets; index++) {
			newPets[index] = pets[index];
		}
		delete[] pets;
		pets = newPets;
	}

	string getName() {
		return name;
	}

	int getLevel() {
		return level;
	}
	
	int getExperiencePoints() {
		return experiencePoints;
	}

	int getMaxNumberOfFightingPets() {
		return maxNumberOfFightingPets;
	}

	void setName(string name) {
		this->name = name;
	}

	void setMaxNumberOfFightingPets(int maxNumberOfFightingPets) {
		this->maxNumberOfFightingPets = maxNumberOfFightingPets;
	}


};
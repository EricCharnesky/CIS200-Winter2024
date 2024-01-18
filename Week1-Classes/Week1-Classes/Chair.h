#pragma once

#include <string>

using namespace std;

class Chair {
private:
	string color;
	double heightInMeters;
	bool hasWheels;
	static int id;

public:
	// default - no argument constructor
	Chair() {
		color = "";
		heightInMeters = 0;
		hasWheels = false;
	}

	// parametized constructor
	Chair(string color, double heightInMeters, bool hasWheels) {
		//setColor(color);
		this->color = color;
		setHeightInMeters(heightInMeters);
		setHasWheels(hasWheels);
	}

	/*void setColor(string color) {
		this->color = color;
	};*/

	string getColor() {
		return color;
	}

	double getHeightInMeters() {
		return heightInMeters;
	}

	void setHeightInMeters(double heightInMeters) {
		if (heightInMeters < 0) {
			// TODO - figure out exceptions
			heightInMeters = 0;
		}
		this->heightInMeters = heightInMeters;

		if (heightInMeters < 0) {
			// TODO - figure out exceptions
			this->heightInMeters = 0;
		}
		else {
			this->heightInMeters = heightInMeters;
		}
	}

	void setHasWheels(bool hasWheels) {
		this->hasWheels = hasWheels;
	}

	bool getHasWheels() {
		return hasWheels;
	}
};
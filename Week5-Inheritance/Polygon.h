#pragma once

#include <vector>

using namespace std;

class Polygon {
private:
	int numberOfSides;
	vector<double> sideLengths;
	
// all child / derived / sub classes have direct access
protected:
	

public:
	Polygon(int numberOfSides) {
		this->numberOfSides = numberOfSides;
		sideLengths = vector<double>(numberOfSides);
		// not needed, but it makes me feel better
		for (int index = 0; index < numberOfSides; index++) {
			sideLengths.at(index) = 0;
		}
	}

	virtual void setSideLength(double length, int sideIndex) {
		sideLengths.at(sideIndex) = length;
	}

	double getSideLength(int sideIndex) {
		return sideLengths.at(sideIndex);
	}

	double getPerimeter() {
		double sum = 0;
		for (double sideLength : sideLengths) {
			sum += sideLength;
		}
		return sum;
	}

	// virtual keyword says this should get overridden
	// pure virutal functions = 0
	// having a pure virtual function makes the class abstract
	virtual double getArea() = 0;
};
#pragma once

#include "Polygon.h"

class Rectangle : public Polygon
{
private:

public:
	Rectangle(double length, double width) : Polygon(4) {
		setSideLength(length, 0);
		setSideLength(width, 1);
	}

	// overriding the polygon version of this function
	void setSideLength(double sideLength, int sideIndex) override {
		if (sideIndex % 2 == 0) {
			// runs the parent class version
			Polygon::setSideLength(sideLength, 0);
			Polygon::setSideLength(sideLength, 2);
		}
		else {
			Polygon::setSideLength(sideLength, 1);
			Polygon::setSideLength(sideLength, 3);
		}
	}

	double getArea() override {
		return getSideLength(0) * getSideLength(1);
	}
};
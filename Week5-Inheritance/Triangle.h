#pragma once

#include <math.h>
#include "Polygon.h"

class Triangle : public Polygon {
private:

public:
	Triangle(double sideLengthA, double sideLengthB, double sideLengthC) 
		: Polygon(3) {
		setSideLength(sideLengthA, 0);
		setSideLength(sideLengthB, 1);
		setSideLength(sideLengthC, 2);
	}

	double getArea() override {
		double semiPerimeter = getPerimeter() / 2;
		return sqrt(semiPerimeter
			* (semiPerimeter - getSideLength(0))
			* (semiPerimeter - getSideLength(1))
			* (semiPerimeter - getSideLength(2)));
	}
};
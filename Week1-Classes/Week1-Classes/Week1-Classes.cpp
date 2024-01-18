
#include <iostream>
#include "Chair.h"

using namespace std;

void printChairDetails(Chair chair) {
	cout << "Color: " << chair.getColor() << endl;
	cout << "Height in meters: " << chair.getHeightInMeters() << endl;
	cout << "Has Wheels: " << chair.getHasWheels() << endl;
}


int main()
{
	Chair ericsChair;
	//ericsChair.setColor("blue");
	ericsChair.setHasWheels(true);
	ericsChair.setHeightInMeters(.7);

	Chair jebsChair("red", .5, false);
	//jebsChair.setColor("red");
	//jebsChair.setHasWheels(false);
	//jebsChair.setHeightInMeters(.5);

	printChairDetails(ericsChair);
	printChairDetails(jebsChair);

	jebsChair = ericsChair;

	printChairDetails(ericsChair);
	printChairDetails(jebsChair);

	ericsChair.setHeightInMeters(1);

	printChairDetails(ericsChair);
	printChairDetails(jebsChair);

	ericsChair.setHeightInMeters(-5);
	printChairDetails(ericsChair);


}

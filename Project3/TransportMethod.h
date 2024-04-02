#pragma once

class TransportMethod {
private:
	int numberOfItemsUntilFull;
	int currentNumberOfItems;
	int minutesForOneWayTrip;
	int timeUntilFullyLoaded;
public:
	TransportMethod(int numberOfItemsUntilFull, int minutesForOneWayTrip) {
		currentNumberOfItems = 0;
		this->numberOfItemsUntilFull = numberOfItemsUntilFull;
		this->minutesForOneWayTrip = minutesForOneWayTrip;
		timeUntilFullyLoaded = 0;
	}

	int loadItem(int currentTime) {
		currentNumberOfItems++;
		if (currentNumberOfItems == numberOfItemsUntilFull) {
			timeUntilFullyLoaded = currentTime + minutesForOneWayTrip;
		}
		return currentTime + minutesForOneWayTrip * 2;
	}

	int getTimeUntilFullyLoaded() {
		return timeUntilFullyLoaded;
	}
};
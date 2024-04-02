#pragma once

#include <queue>
#include <stack>
#include <vector>
#include "TransportMethod.h"
#include <string>

using namespace std;

class Dock {
private:
	queue<int> planeItems;
	queue<stack<int>> trainItems;
	vector<TransportMethod> trains;
	vector<TransportMethod> planes;

public:
	Dock(vector<int> numberOfItemsPerTrain, vector<int> numberOfItemsPerPlane,
		vector<int> trainItems, vector<int> planeItems) {
		for (int index = 0; index < numberOfItemsPerTrain.size(); index++ ) {
			trains.push_back(TransportMethod(numberOfItemsPerTrain.at(index), index + 1));
		}

		for (int index = 0; index < numberOfItemsPerPlane.size(); index++) {
			planes.push_back(TransportMethod(numberOfItemsPerPlane.at(index), (index + 1)*5));
		}

		stack<int> trainItemStack;

		for (int trainItem : trainItems) {

			if (trainItemStack.size() == 5) {
				this->trainItems.push(trainItemStack);
				stack<int> trainItemStack;
			}

			trainItemStack.push(trainItem);
		}

		this->trainItems.push(trainItemStack);

		for (int planeItem : planeItems) {
			this->planeItems.emplace(planeItem);
		}
	}

	string load() {
		int currentTime = 0;
		while (!trainItems.empty()) {
			stack<int> currentStack = trainItems.front();
			trainItems.pop();
			while (!currentStack.empty()) {
				int trainNumber = currentStack.top();
				currentStack.pop();
				currentTime = trains.at(trainNumber - 1).loadItem(currentTime);
			}
		}

		currentTime = 0;
		while (!planeItems.empty()) {
			int planeNumber = planeItems.front();
			planeItems.pop();
			currentTime = planes.at(planeNumber - 1).loadItem(currentTime);
		}

		string timings = "";

		for (TransportMethod train : trains) {
			timings += to_string(train.getTimeUntilFullyLoaded()) + " ";
		}
		timings += "\n";

		for (TransportMethod plane : planes) {
			timings += to_string(plane.getTimeUntilFullyLoaded()) + " ";
		}

		return timings;
	}

};
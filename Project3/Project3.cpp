
#include <iostream>
#include <vector>
#include "Dock.h"

using namespace std;

int main()
{
    vector<int> numberOfItemsForTrains = { 2, 7, 1 };
    vector<int> numberOfItemsForPlanes = { 3, 2 };
    vector<int> trainItems = { 2, 2, 2, 1, 3, 2, 2, 2, 1, 2 };
    vector<int> planeItems = { 2, 1, 1, 2, 1 };

    Dock dock(numberOfItemsForTrains, numberOfItemsForPlanes, trainItems, planeItems);
    cout << dock.load() << endl;
}


#include <iostream>
#include <vector>


using namespace std;


// O(n) - has to check all n values
bool containsInUnsortedList(vector<int> numbers, int valueToFind) {
	for (int number : numbers) {
		if (number == valueToFind) {
			return true;
		}
	}
	return false;
}

// O(log n)
bool _containsInSortedList(vector<int> numbers, int valueToFind, int startIndex, int endIndex) {
	int middleIndex = (endIndex + startIndex) / 2;
	// base case - did find
	if (valueToFind == numbers.at(middleIndex)) {
		return true;
	}
	// base case - not found
	else if (startIndex == endIndex) {
		return false;
	}

	if (valueToFind < numbers.at(middleIndex)) {
		return _containsInSortedList(numbers, valueToFind, startIndex, middleIndex - 1);
	}
	return _containsInSortedList(numbers, valueToFind, middleIndex + 1, endIndex);

}

bool containsInSortedList(vector<int> numbers, int valueToFind) {
	return _containsInSortedList(numbers, valueToFind, 0, numbers.size() - 1);
}

// O(n^2)
void selectionSort(vector<int>& numbers) {

	for (int sortedIndex = 0; sortedIndex < numbers.size() - 1; sortedIndex++) {
		int smalledValueIndex = sortedIndex;
		for (int currentIndex = sortedIndex + 1; currentIndex < numbers.size(); currentIndex++) {
			if (numbers.at(currentIndex) < numbers.at(smalledValueIndex)) {
				smalledValueIndex = currentIndex;
			}
		}
		int temp = numbers.at(smalledValueIndex);
		numbers.at(smalledValueIndex) = numbers.at(sortedIndex);
		numbers.at(sortedIndex) = temp;
	}
}

// O(n^2) - but best case of O(n)
void insertionSort(vector<int>& numbers) {
	for (int currentIndex = 1; currentIndex < numbers.size(); currentIndex++) {
		for (int indexToCheck = currentIndex; indexToCheck > 0 && numbers.at(indexToCheck) < numbers.at(indexToCheck - 1); indexToCheck--) {
			int temp = numbers.at(indexToCheck - 1);
			numbers.at(indexToCheck - 1) = numbers.at(indexToCheck);
			numbers.at(indexToCheck) = temp;
		}
	}
}



int main()
{
	vector<int> sortedList = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	cout << containsInSortedList(sortedList, 0) << endl;
	cout << containsInSortedList(sortedList, 2) << endl;
	cout << containsInSortedList(sortedList, 6) << endl;
	cout << containsInSortedList(sortedList, 11) << endl;

	vector<int> numbers = { 13, 7, 26, 5 };
	insertionSort(numbers);
	for (int number : numbers) {
		cout << number << endl;
	}
}

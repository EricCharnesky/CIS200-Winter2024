#include <string>

using namespace std;

class Student {
private:
	string name;
	int number;
public:
	Student(int number, string name) {
		this->name = name;
		this->number = number;
	}

	string getName() {
		return name;
	}

	int getNumber() {
		return number;
	}

	bool operator<(Student& other) {
		return number < other.number;
	}

	bool operator>= (Student& other) {

	}

};
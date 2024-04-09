#pragma once

#include <string>
#include <vector>
#include "Assignment.h"

using namespace std;

class Student {
private:
	
	string name;
	vector<Assignment> assignments;

public:

	Student() {
		setName("");
	}

	Student(string name) {
		setName(name);
	}

	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return name;
	}

	vector<Assignment> getAssignments() {
		return assignments;
	}

	void setAssignments(vector<Assignment> assignments) {
		this->assignments = assignments;
	}

	double getGrade() {
		double totalPointsPossible = 0;
		double totalPoitsEarned = 0;

		for (Assignment assignment : assignments) {
			totalPointsPossible += assignment.getPointsPossible();
			totalPoitsEarned += assignment.getPointsEarned();
		}

		return totalPoitsEarned / totalPointsPossible;
	}

};
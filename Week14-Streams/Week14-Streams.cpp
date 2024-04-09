
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

int main()
{

	vector<Student> students;

	ifstream inputFileStream;

	string filename;

	cout << "Enter the name of your gradebook to load" << endl;

	cin >> filename;

	inputFileStream.open(filename);

	if (!inputFileStream.is_open()) {
		cout << "Could not open a file named " << filename << endl;
	}
	else {

		while (!inputFileStream.eof() && inputFileStream.good()) {
			string name;
			int numberOfAssignments;
			inputFileStream >> name;
			inputFileStream >> numberOfAssignments;

			if (!inputFileStream.fail()) {
				Student student(name);
				vector<Assignment> assignments;
				for (int assignment = 0; assignment < numberOfAssignments; assignment++) {
					string assignmentName;
					double pointsPossible;
					double pointsEarned;
					inputFileStream >> assignmentName;
					inputFileStream >> pointsPossible;
					inputFileStream >> pointsEarned;

					assignments.push_back(Assignment(assignmentName, pointsPossible, pointsEarned));
				}
				student.setAssignments(assignments);
				students.push_back(student);
			}
		}

	}





	string input;

	while (input != "Done") {
		cout << "Enter 1 to list students, 2 to add a student, or Done to be all done" << endl;
		cin >> input;

		if (input == "1") {
			for (Student student : students) {
				cout << student.getName() << endl;
				cout << student.getGrade() << endl;

				for (Assignment assignment : student.getAssignments()) {
					cout << assignment.getName() << endl;
					cout << "Points Possible: " << assignment.getPointsPossible() << endl;
					cout << "Points Earned: " << assignment.getPointsEarned() << endl;
				}
			}
		}
		else if (input == "2") {

			Student student;

			cout << "Enter the student name" << endl;

			cin >> input;

			student.setName(input);

			string assignmentName;

			vector<Assignment> assignments;

			while (assignmentName != "Done") {
				cout << "Enter an assignment name or Done" << endl;
				cin >> assignmentName;

				if (assignmentName != "Done") {
					double pointsPossible;
					double pointsEarned;

					cout << "Enter the points possilbe" << endl;
					cin >> pointsPossible;

					cout << "Enter the points earned" << endl;
					cin >> pointsEarned;

					assignments.push_back(Assignment(assignmentName, pointsPossible, pointsEarned));

				}

				student.setAssignments(assignments);
			}


			students.push_back(student);

		}
	}

	ofstream outputFileStraem;
	outputFileStraem.open("gradebook.txt");

	for (Student student : students) {
		outputFileStraem << student.getName() << endl;
		auto assignments = student.getAssignments();
		outputFileStraem << assignments.size() << endl;

		for (Assignment assignment : assignments) {
			outputFileStraem << assignment.getName() << endl;
			outputFileStraem << assignment.getPointsPossible() << endl;
			outputFileStraem << assignment.getPointsEarned() << endl;
		}
	}

	outputFileStraem.close();

}

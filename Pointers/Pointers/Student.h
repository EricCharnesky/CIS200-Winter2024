#pragma once

using namespace std;

#include <string>
#include <stdexcept>

class Student {
private:
	static const int MAX_SCORES = 50;

	string name;
	int id;
	double score;
	int* scores;

	void initializeScoreArray() {
		// TODO - FIX ME
		/*if (scores != nullptr) {
			delete[] scores;
		}*/
		
		scores = new int[MAX_SCORES];
		for (int index = 0; index < MAX_SCORES; index++) {
			scores[index] = UNSCORED;
		}
	}

	void checkForValidScoresIndex(int index)
	{
		if (index < 0 or index >= MAX_SCORES) {
			throw range_error("invalid index");
		}
	}
public:

	// belongs at the class defintion level, not for each instance
	static const int UNSCORED = -1;

	Student(string name = "", int id = 0, double score = 100) {
		this->name = name;
		this->id = id;
		setScore(score);
		initializeScoreArray();
	}

	// copy constructor
	Student(const Student& other) {
		name = other.name;
		id = other.id;
		score = other.score;
		initializeScoreArray();
		for (int index = 0; index < MAX_SCORES; index++) {
			scores[index] = other.scores[index];
		}
	}

	// copy assignment operator
	// someStudentVarible = someOtherStudentVariable;
	Student& operator=(const Student& other) {
		name = other.name;
		id = other.id;
		score = other.score;
		initializeScoreArray();
		for (int index = 0; index < MAX_SCORES; index++) {
			scores[index] = other.scores[index];
		}

		return *this;
	}

	// destructor
	~Student() {
		delete[] scores;
	}

	string getName() {
		return this->name;
	}

	int getId() {
		return this->id;
	}

	double getScore() {
		return this->score;
	}

	void setName(string name) {
		this->name = name;
	}

	void setId(int id) {
		this->id = id;
	}

	void setScore(double score) {
		if (score < 0 || score > 100) {
			throw logic_error("invalid score");
		}
		this->score = score;
	}

	void setScore(int index, int score) {
		checkForValidScoresIndex(index);
		scores[index] = score;
	}

	int getScore(int index) {
		checkForValidScoresIndex(index);
		return scores[index];
	}
};
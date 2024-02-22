#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MazeSolver {
private:
	vector<vector<char>> maze;

	int currentNumberOfSteps;
	int shortestNumberOfStepsForSolution;
	string shortestSolution;

	bool canGoTo(int rowIndex, int columnIndex) {
		return rowIndex >= 0 && rowIndex < maze.size()
			&& columnIndex >= 0 && columnIndex < maze.at(rowIndex).size()
			&& (maze.at(rowIndex).at(columnIndex) == ' ' ||
				maze.at(rowIndex).at(columnIndex) == 'E');
	}

	void mazeSolver(int rowIndex, int columnIndex) {
		if (maze.at(rowIndex).at(columnIndex) == 'E') {
			if (currentNumberOfSteps < shortestNumberOfStepsForSolution) {
				shortestNumberOfStepsForSolution = currentNumberOfSteps;
				shortestSolution = "";
				for (vector<char> row : maze) {
					for (char space : row) {
						shortestSolution += space;
					}
					shortestSolution += "\n";
				}
			}
		}
		// mark the current space
		maze.at(rowIndex).at(columnIndex) = '.';
		currentNumberOfSteps++;

		// U R D L
		// can go up?
		if (canGoTo(rowIndex - 1, columnIndex)) {
			mazeSolver(rowIndex - 1, columnIndex);
		}
		// can go right?
		if (canGoTo(rowIndex, columnIndex + 1)) {
			mazeSolver(rowIndex, columnIndex + 1);
		}
		// can go down?
		if (canGoTo(rowIndex + 1, columnIndex)) {
			mazeSolver(rowIndex + 1, columnIndex);
		}
		// can go left?
		if (canGoTo(rowIndex, columnIndex - 1)) {
			mazeSolver(rowIndex, columnIndex - 1);
		}

		currentNumberOfSteps--;
		maze.at(rowIndex).at(columnIndex) = ' ';
	}

	

public:

	MazeSolver(vector<vector<char>> maze) {
		this->maze = maze;
		currentNumberOfSteps = 0;
		shortestNumberOfStepsForSolution = INT32_MAX;
		shortestSolution = "";

		for (int rowIndex = 0; rowIndex < maze.size(); rowIndex++) {
			for (int columnIndex = 0; columnIndex < maze.at(rowIndex).size(); columnIndex++) {
				if (maze.at(rowIndex).at(columnIndex) == 'S') {
					mazeSolver(rowIndex, columnIndex);
				}
			}
		}
	}

	int getShortestNumberOfStepsForSolution() {
		return shortestNumberOfStepsForSolution;
	}

	bool hasSolution() {
		return shortestSolution != "";
	}

	string toString() {
		return shortestSolution;
	}
};
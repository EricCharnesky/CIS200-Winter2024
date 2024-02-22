#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Sudoku {
private:
	vector<vector<int>> board;

	bool canPlaceNumberInSubGrid(int number, int rowIndex, int columnIndex) {
		int startingRowIndex = rowIndex / 3 * 3;
		int startingColumnIndex = columnIndex / 3 * 3;

		for (int rowIndex = startingRowIndex; rowIndex < startingRowIndex + 3; rowIndex++) {
			for (int columnIndex = startingColumnIndex; columnIndex < startingColumnIndex + 3; columnIndex++) {
				if (board.at(rowIndex).at(columnIndex) == number) {
					return false;
				}
			}
		}

		return true;
	}

	bool canPlaceNumberInColumn(int number, int columnIndex) {
		for (int rowIndex = 0; rowIndex < board.size(); rowIndex++) {
			if (board.at(rowIndex).at(columnIndex) == number) {
				return false;
			}
		}
		return true;
	}

	bool canPlaceNumberInRow(int number, int rowIndex) {
		for (int columnIndex = 0; columnIndex < board.size(); columnIndex++) {
			if (board.at(rowIndex).at(columnIndex) == number) {
				return false;
			}
		}
		return true;
	}

	bool canPlaceNumber(int number, int rowIndex, int columnIndex) {
		return canPlaceNumberInRow(number, rowIndex) &&
			canPlaceNumberInColumn(number, columnIndex) &&
			canPlaceNumberInSubGrid(number, rowIndex, columnIndex);
	}

	bool isSolved() {
		// could use a cool STL function to search
		for (int rowIndex = 0; rowIndex < board.size(); rowIndex++) {
			for (int columnIndex = 0; columnIndex < board.at(rowIndex).size(); columnIndex++) {
				if (board.at(rowIndex).at(columnIndex) == 0) {
					return false;
				}
			}
		}
		return true;
	}

	void solve() {
		for (int rowIndex = 0; rowIndex < board.size(); rowIndex++) {
			for (int columnIndex = 0; columnIndex < board.at(rowIndex).size(); columnIndex++) {
				if (board.at(rowIndex).at(columnIndex) == 0) {
					for (int number = 0; number < 10; number++) {
						if (canPlaceNumber(number, rowIndex, columnIndex)) {
							board.at(rowIndex).at(columnIndex) = number;
							solve();
							if (!isSolved()) {
								board.at(rowIndex).at(columnIndex) = 0;
							}
						}
					}
					// stoping after the first 0 it finds
					return;
				}
			}
		}


		
	}

public:
	Sudoku(vector<vector<int>> board)
	{
		this->board = board;
		solve();
	}

	string toString() {
		string solution = "-------------------\n";
		for (vector<int> row : board) {
			for (int spot : row) {
				if (spot != 0) {
					solution += "|" + to_string(spot);
				}
				else {
					solution += "| ";
				}
				
			}
			solution += "|\n";
			solution += "-------------------\n";
		}

		return solution;
	}

};
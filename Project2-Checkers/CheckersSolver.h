#pragma once

#include <vector>
#include <iostream>

using namespace std;

class CheckersSolver {
private:
	vector<vector<char>> board;
	int maxJumps;
	int currentJumps;

	void calculateJumps(int rowIndex, int columnIndex) {
		if (currentJumps > maxJumps) {
			maxJumps = currentJumps;
		}
		
		// up left
		tryJump(rowIndex, columnIndex, -2, -2);

		// up right
		tryJump(rowIndex, columnIndex, -2, 2);

		// down right
		tryJump(rowIndex, columnIndex, 2, 2);

		// down left
		tryJump(rowIndex, columnIndex, 2, -2);

	}

	void tryJump(int currentRowIndex, int currentColumnIndex, int rowChange, int columnChange)
	{
		if (currentRowIndex + rowChange >= 0 and currentColumnIndex + columnChange >= 0 and
			currentRowIndex + rowChange < board.size() and currentColumnIndex + columnChange < board.size() and
			board.at(currentRowIndex + rowChange).at(currentColumnIndex + columnChange) == ' ' and
			board.at(currentRowIndex + (rowChange/2)).at(currentColumnIndex + (columnChange/2)) == BLACK)
		{
			currentJumps++;
			board.at(currentRowIndex).at(currentColumnIndex) = ' ';
			board.at(currentRowIndex + rowChange/2).at(currentColumnIndex + columnChange/2) = ' ';
			board.at(currentRowIndex + rowChange).at(currentColumnIndex + columnChange) = WHITE;
			calculateJumps(currentRowIndex + rowChange, currentColumnIndex + columnChange);
			board.at(currentRowIndex + rowChange).at(currentColumnIndex + columnChange) = ' ';
			board.at(currentRowIndex + rowChange/2).at(currentColumnIndex + columnChange/2) = BLACK;
			board.at(currentRowIndex).at(currentColumnIndex) = WHITE;
			currentJumps--;
		}
	}

public:
	static const char WHITE = 'W';
	static const char BLACK = 'B';

	CheckersSolver(vector<vector<char>> board) {
		this->board = board;
		maxJumps = 0;
		currentJumps = 0;

		bool piecesAreOnWhiteSquares = false;
		bool piecesAreOnBlackSquares = false;

		if (board.size() != 8) {
			// this is a bad way to validate, please use exceptions
			cout << "INVALID NUMBER OF ROWS" << endl;
		}
		for (int rowIndex = 0; rowIndex < 8; rowIndex++) {
			if (board.at(rowIndex).size() != 8) {
				cout << "INVALID WIDTH" << endl;
			}
			for (int columnIndex = 0; columnIndex < 8; columnIndex++) {
				if (board.at(rowIndex).at(columnIndex) != ' ') {
					if ((rowIndex + columnIndex) % 2 == 0) {
						piecesAreOnWhiteSquares = true;
					}
					else {
						piecesAreOnBlackSquares = true;
					}
				}
			}
		}

		if (piecesAreOnBlackSquares && piecesAreOnWhiteSquares) {
			cout << "You can't have pieces on both colored squares!" << endl;
		}


	}

	int getMaxJumps() {
		for (int rowIndex = 0; rowIndex < 8; rowIndex++) {
			for (int columnIndex = 0; columnIndex < 8; columnIndex++) {
				if (board.at(rowIndex).at(columnIndex) == WHITE) {
					calculateJumps(rowIndex, columnIndex);
				}
			}
		}

		return maxJumps;
	}

	// https://github.com/EricCharnesky/CIS200-Winter2024/blob/main/Lab6/Lab6/Lab6.cpp#L7
	void printBoard() {
		cout << "-----------------" << endl;
		for (vector<char> row : board) {
			for (char spot : row) {
				cout << "|" << spot;
			}
			cout << "|" << endl;
			cout << "-----------------" << endl;
		}
	}

};
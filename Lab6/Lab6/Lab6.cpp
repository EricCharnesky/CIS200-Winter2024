
#include <iostream>
#include <vector>

using namespace std;

void printBoard(vector<vector<char>>& const board) {
    cout << "-----------------" << endl;
    for (vector<char> row : board) {
        for (char spot : row) {
            cout << "|" << spot;
        }
        cout << "|" << endl;
        cout << "-----------------" << endl;
    }
}

int main()
{
    vector<vector<char>> board = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    vector<vector<char>> lessLinesBoard = vector<vector<char>>(8, vector<char>(8, ' '));

    printBoard(board);

    printBoard(lessLinesBoard);
}
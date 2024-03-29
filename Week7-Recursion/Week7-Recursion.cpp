

#include <iostream>
#include <vector>
#include "MazeSolver.h"
#include "Sudoku.h"

using namespace std;

// https://www.codespeedy.com/solution-of-tower-of-hanoi-problem-in-cpp/
void TowerOfHanoi(int num, char A, char B, char C) {
    if (num > 0) {
        TowerOfHanoi(num - 1, A, C, B);
        cout << "Move a disk " << num << " from " << " " << A << " to" << " " << C << endl;
        TowerOfHanoi(num - 1, B, A, C);
    }
}

// interative solution - it's ugly
// https://codereview.stackexchange.com/questions/137997/tower-of-hanoi-without-recursion


int iterative_fib(int nth) {
    if (nth <= 2) {
        return 1;
    }

    int currentNth = 2;
    int current = 1;
    int previous = 1;

    while (currentNth != nth) {
        int next = current + previous;
        currentNth++;
        previous = current;
        current = next;
    }

    return current;
}

int _fib_helper(int nth, int currentNth, int current, int previous) {
    if (currentNth == nth) {
        return current;
    }
    return _fib_helper(nth, currentNth + 1, current + previous, current);
}

int better_fib(int nth) {
    // base case - can solve
    if (nth <= 2) {
        return 1;
    }

    return _fib_helper(nth, 2, 1, 1);
}

// bad fib
int fib(int nth) {
    // base case - can solve
    if (nth <= 2) {
        return 1;
    }

    return fib(nth - 1) + fib(nth - 2);
}

void countDown(int number) {
    if (number <= 0) {
        cout << "Blast off!" << endl;
    }
    else {
        cout << number << endl;

        // this is the recursive piece
        countDown(number - 1);
    }
}


int main()
{
    vector<vector<int>> board{
        { 0, 7, 0, 0, 2, 0, 0, 4, 6 },
        { 0, 6, 0, 0, 0, 0, 8, 9, 0 },
        { 2, 0, 0, 8, 0, 0, 7, 1, 5 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    Sudoku sudokuSolver(board);

    cout << sudokuSolver.toString();
    cout << endl;


    vector<vector<char>> maze{
        { 'S', 'X', 'X', 'X', ' ' },
        { ' ', ' ', ' ', 'X', ' ' },
        { ' ', 'X', ' ', ' ', ' ' },
        { ' ', 'X', ' ', 'X', 'E' },
        { ' ', 'X', ' ', ' ', ' ' }
    };

    MazeSolver solver(maze);

    cout << solver.toString() << endl;
    cout << "shortest solution is " << solver.getShortestNumberOfStepsForSolution() << " steps" << endl;

    



    for (int n = 1; n <= 50; n++) {
        cout << n << "th fib: " << better_fib(n) << endl;
    }
}

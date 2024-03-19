
#include <iostream>
#include "CheckersSolver.h"

int main()
{
    vector<vector<char>> board = {
       {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', 'B', ' ', ' ', ' ', 'B', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', 'B', ' ', 'B', ' ', ' '},
       {' ', ' ', 'W', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', 'B', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B'}
    };

    CheckersSolver solver(board);
    cout << solver.getMaxJumps() << endl;
}

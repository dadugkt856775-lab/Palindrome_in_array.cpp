#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& board,
            int row, int col, int num) {

    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num)
            return false;

        if (board[i][col] == num)
            return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {

            if (board[row][col] == 0) {

                for (int num = 1; num <= 9; num++) {

                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;

                        if (solve(board))
                            return true;

                        board[row][col] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<vector<int>> board(9, vector<int>(9));

    for (auto& row : board)
        for (int& x : row)
            cin >> x;

    if (solve(board)) {
        for (auto& row : board) {
            for (int x : row)
                cout << x << " ";
            cout << "\n";
        }
    } else {
        cout << "No Solution";
    }

    return 0;
}

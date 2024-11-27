#include <iostream>
#include <vector>
using namespace std;

class NQueens {
private:
    int boardSize;
    vector<vector<int>> board;

public:
    NQueens(int size) : boardSize(size) {
        board.resize(boardSize, vector<int>(boardSize, 0));
    }

    void printSolution() {
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                cout << (board[i][j] ? "Q " : ". ");
            }
            cout << endl;
        }
    }

    bool isSafe(int row, int col) {
        for (int i = 0; i < row; i++)
            if (board[i][col]) return false;

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j]) return false;

        for (int i = row, j = col; i >= 0 && j < boardSize; i--, j++)
            if (board[i][j]) return false;

        return true;
    }

    bool solveNQueensUtil(int row) {
        if (row >= boardSize) return true;

        for (int col = 0; col < boardSize; col++) {
            if (isSafe(row, col)) {
                board[row][col] = 1;
                if (solveNQueensUtil(row + 1)) return true;
                board[row][col] = 0;
            }
        }
        return false;
    }

    void solve() {
        if (solveNQueensUtil(0)) {
            printSolution();
        } else {
            cout << "No solution exists." << endl;
        }
    }
};

int main() {
    int boardSize;
    cout << "Enter the size of the chessboard (N): ";
    cin >> boardSize;

    NQueens nQueens(boardSize);
    nQueens.solve();

    return 0;
}

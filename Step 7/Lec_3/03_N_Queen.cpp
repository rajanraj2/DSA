// https://leetcode.com/problems/n-queens/description/
// N-Queens


class Solution {
private:
    void solve(vector<vector<string>>& result, vector<string>& board, int n, int col,
     vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal) {
        if (col >= n) {
            result.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (!leftRow[row] && !upperDiagonal[col + n - 1 - row] && !lowerDiagonal[col + row]) {
                leftRow[row] = 1;
                upperDiagonal[col + n - 1 - row] = 1;
                lowerDiagonal[col + row] = 1;
                board[row][col] = 'Q';
                solve(result, board, n, col + 1, leftRow, upperDiagonal, lowerDiagonal);
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[col + n - 1 - row] = 0;
                lowerDiagonal[col + row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> board(n, s);
        vector<vector<string>> result;
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(result, board, n, 0, leftRow, upperDiagonal, lowerDiagonal);
        return result;
    }
};


// class Solution {
// private:
//     bool isSafe(vector<string>& board, int row, int col, int n) {
//         int r = row, c = col;

//         while (row >= 0 && col >= 0) {
//             if (board[row][col] == 'Q') return false;
//             row--;
//             col--;
//         }

//         row = r;
//         col = c;
//         while (col >= 0) {
//             if (board[row][col] == 'Q') return false;
//             col--;
//         }

//         row = r;
//         col = c;
//         while (row < n && col >= 0) {
//             if (board[row][col] == 'Q') return false;
//             row++;
//             col--;
//         }
//         return true;
//     }

//     void solve(vector<vector<string>>& result, vector<string>& board, int n, int col) {
//         if (col >= n) {
//             result.push_back(board);
//             return;
//         }

//         for (int row = 0; row < n; row++) {
//             if (isSafe(board, row, col, n)) {
//                 board[row][col] = 'Q';
//                 solve(result, board, n, col + 1);
//                 board[row][col] = '.';
//             }
//         }
//     }

// public:
//     vector<vector<string>> solveNQueens(int n) {
//         string s(n, '.');
//         vector<string> board(n, s);
//         vector<vector<string>> result;
//         solve(result, board, n, 0);
//         return result;
//     }
// };
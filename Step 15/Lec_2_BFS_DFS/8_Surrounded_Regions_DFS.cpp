// Link - https://leetcode.com/problems/surrounded-regions/
// Surrounded Regions


class Solution {
private:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int delrow[], int delcol[], int n, int m, int row, int col) {
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(board, vis, delrow, delcol, n, m, nrow, ncol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                dfs(board, vis, delrow, delcol, n, m, 0, j);
            }
            if (board[n - 1][j] == 'O' && !vis[n - 1][j]) {
                dfs(board, vis, delrow, delcol, n, m, n - 1, j);
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(board, vis, delrow, delcol, n, m, i, 0);
            }
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                dfs(board, vis, delrow, delcol, n, m, i, m - 1);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

    }
};
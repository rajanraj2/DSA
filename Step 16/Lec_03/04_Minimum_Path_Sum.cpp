// https://leetcode.com/problems/minimum-path-sum/
// Minimum Path Sum


// Memoization

// class Solution {
// public:
//     int helper(int i, int j, vector<vector<int>>& grid, int &m, int &n, vector<vector<int>> &dp) {
//         if (i == m - 1 && j == n - 1) {
//             return grid[i][j];
//         }
//         if (i >= m || j >= n) return INT_MAX;
//         if (dp[i][j] != -1) return dp[i][j];

//         int val1 = helper(i + 1, j, grid, m, n, dp);
//         int val2 = helper(i, j + 1, grid, m, n, dp);
//         return dp[i][j] = grid[i][j] + min(val1, val2);
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int> (n, -1));
//         return helper(0, 0, grid, m, n, dp);
//     }
// };


// Tabulation

// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int> (n, 0));
//         dp[0][0] = grid[0][0];
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i == 0 && j == 0) continue;
//                 int val1 = INT_MAX, val2 = INT_MAX;
//                 if (i > 0) val1 = dp[i - 1][j];
//                 if (j > 0) val2 = dp[i][j - 1];
//                 dp[i][j] = grid[i][j] + min(val1, val2); 
//             }
//         }
//         return dp[m - 1][n - 1];
//     }    
// };


// Space Optimisation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n, 0);
        
        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = grid[i][j];
                    continue;
                }
                int val1 = INT_MAX, val2 = INT_MAX;
                if (i > 0) val1 = prev[j];
                if (j > 0) val2 = temp[j - 1];
                temp[j] = grid[i][j] + min(val1, val2); 
            }
            prev = temp;
        }
        return prev[n - 1];
    }    
};  
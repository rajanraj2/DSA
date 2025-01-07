// https://leetcode.com/problems/unique-paths-ii/description/
// Unique Paths II


// Space Optimised

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                if (i == 0 && j == 0) temp[j] = 1;  
                else {
                    int down = 0, right = 0;
                    down = prev[j];
                    if (j > 0) right = temp[j - 1];
                    temp[j] = down + right;
                }
            }
            prev = temp;
        }
        return prev[n - 1];
    }
};


// Tabulation

// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int> (n, -1));
//         dp[0][0] = 1;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (obstacleGrid[i][j] == 1) {
//                     dp[i][j] = 0;
//                     continue;
//                 }
//                 if (i == 0 && j == 0) continue;
//                 int down = 0, right = 0;
//                 if (i > 0) down = dp[i - 1][j];
//                 if (j > 0) right = dp[i][j - 1];
//                 dp[i][j] = down + right;
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };


// Recursion

// class Solution {
// public:
//     int helper(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<int>>& grid) {
//         if (i == m - 1 && j == n - 1) return (grid[i][j] ^ 1);
//         if (i >= m || j >= n) return 0;
//         if (grid[i][j] == 1) return 0;

//         if (dp[i][j] != -1) return dp[i][j];
//         dp[i][j] = helper(i + 1, j, m, n, dp, grid) + helper(i, j + 1, m, n, dp, grid);
//         return dp[i][j];
//     }

//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int> (n, -1));
//         return helper(0, 0, m, n, dp, obstacleGrid);
//     }
// };
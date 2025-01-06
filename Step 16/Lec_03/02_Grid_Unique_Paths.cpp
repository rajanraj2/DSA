// https://leetcode.com/problems/unique-paths/description/
// Unique Paths


// Space optimisation

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
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
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int> (n, -1));
//         dp[0][0] = 1;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
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
//     int helper(int i, int j, int m, int n, vector<vector<int>> &dp) {
//         if (i == m - 1 && j == n - 1) return 1;
//         if (i >= m || j >= n) return 0;
//         if (dp[i][j] != -1) return dp[i][j];
//         dp[i][j] = helper(i + 1, j, m, n, dp) + helper(i, j + 1, m, n, dp);
//         return dp[i][j];
//     }

//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int> (n, -1));
//         return helper(0, 0, m, n, dp);
//     }
// };
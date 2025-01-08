// https://leetcode.com/problems/minimum-falling-path-sum/
// Minimum Falling Path Sum


// Recursion - TLE

// class Solution {
// public:
//     int helper(int i, int j, int &m, int &n, vector<vector<int>>& matrix, vector<vector<int>> &dp) {
//         if (i >= m) return 0;
//         if (j < 0 || j >= n) return INT_MAX;
//         if (dp[i][j] != -1) return dp[i][j];
//         int val1 = helper(i + 1, j - 1, m, n, matrix, dp);
//         int val2 = helper(i + 1, j, m, n, matrix, dp);
//         int val3 = helper(i + 1, j + 1, m, n, matrix, dp);
//         return dp[i][j] = matrix[i][j] + min({val1, val2, val3});
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int result = INT_MAX;
//         int m = matrix.size(), n = matrix[0].size();
//         vector<vector<int>> dp(m, vector<int> (n, -1));
//         for (int i = 0; i < n; i++) {
//             result = min(result, helper(0, i, m, n, matrix, dp));
//         }
//         return result;
//     }
// };


// Tabualtion

// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size();
//         vector<vector<int>> dp(m, vector<int> (n, -1));
//         dp[0] = matrix[0];
//         int result = INT_MAX;

//         for (int i = 1; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 int val1 = INT_MAX, val2 = INT_MAX, val3 = INT_MAX;
//                 if (j > 0) val1 = dp[i - 1][j - 1];
//                 val2 = dp[i - 1][j];
//                 if (j < n - 1) val3 = dp[i - 1][j + 1];

//                 dp[i][j] = matrix[i][j] + min({val1, val2, val3});
//                 if (i == m - 1) result = min(result, dp[i][j]);
//             }
//         } 

//         if (m == 1) result = *min_element(matrix[0].begin(), matrix[0].end());
//         return result;     
//     }
// };


// Space optimisation

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> prev(n);
        prev = matrix[0];
        int result = INT_MAX;

        for (int i = 1; i < m; i++) {
            vector<int> temp(n);
            for (int j = 0; j < n; j++) {
                int val1 = INT_MAX, val2 = INT_MAX, val3 = INT_MAX;
                if (j > 0) val1 = prev[j - 1];
                val2 = prev[j];
                if (j < n - 1) val3 = prev[j + 1];

                temp[j] = matrix[i][j] + min({val1, val2, val3});
                if (i == m - 1) result = min(result, temp[j]);
            }
            prev = temp;
        } 

        if (m == 1) result = *min_element(matrix[0].begin(), matrix[0].end());
        return result;     
    }
};
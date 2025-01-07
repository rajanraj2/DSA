// https://leetcode.com/problems/triangle/
// Triangle


// Recursion

// class Solution {
// public:
//     int helper(int i, int ind, int &n, vector<vector<int>> &triangle, int &sum, vector<vector<int>> &dp) {
//         if (i == n || ind >= triangle[i].size()) return 0;
//         if (dp[i][ind] != -1) return dp[i][ind];

//         sum += triangle[i][ind];
//         int val1 = helper(i + 1, ind, n, triangle, sum, dp);
//         int val2 = helper(i + 1, ind + 1, n, triangle, sum, dp);
//         return dp[i][ind] = triangle[i][ind] + min(val1, val2);
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         int sum = 0, n = triangle.size();
//         int m = triangle.back().size();
//         vector<vector<int>> dp(n, vector<int> (m, -1));
//         return helper(0, 0, n, triangle, sum, dp);
//     }
// };


// Tabulation

// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size(), result = INT_MAX;
//         int m = triangle.back().size();
//         vector<vector<int>> dp(n, vector<int> (m, INT_MAX));
//         dp[0][0] = triangle[0][0];

//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < triangle[i].size(); j++) {
//                 int val1 = INT_MAX, val2 = INT_MAX;
//                 val1 = dp[i - 1][j];
//                 if (j > 0) val2 = dp[i - 1][j - 1];
//                 dp[i][j] = triangle[i][j] + min(val1, val2);
//                 if (i == n - 1) {
//                     result = min(result, dp[i][j]);
//                 }
//             }
//         }
//         if (n == 1) return triangle[0][0];
//         return result;
//     }
// };


// Space optimisation

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), result = INT_MAX;
        int m = triangle.back().size();
        vector<int> prev;
        prev.push_back(triangle[0][0]);

        for (int i = 1; i < n; i++) {
            prev.push_back(INT_MAX);
            vector<int> temp(triangle[i].size() + 1, INT_MAX);
            for (int j = 0; j < triangle[i].size(); j++) {
                int val1 = INT_MAX, val2 = INT_MAX;
                val1 = prev[j];
                if (j > 0) val2 = prev[j - 1];
                
                temp[j] = triangle[i][j] + min(val1, val2);
                if (i == n - 1) {
                    result = min(result, temp[j]);
                }
            }
            prev = temp;
        }

        if (n == 1) return triangle[0][0];
        return result;
    }
};
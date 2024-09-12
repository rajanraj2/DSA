// Link - https://leetcode.com/problems/climbing-stairs/
// Climbing Stairs


class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 1; dp[1] = 1;
        for (int i = 2; i <= n; i++)  {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};


// Memoization

// class Solution {
// private:
//     int helper(int n, vector<int>& dp) {
//         if (n <= 1) return 1;
//         if (dp[n] != -1) return dp[n];
//         return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
//     }

// public:
//     int climbStairs(int n) {
//         vector<int> dp(n + 1, -1);
//         return helper(n, dp);
//     }
// };
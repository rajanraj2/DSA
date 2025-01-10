// https://leetcode.com/problems/coin-change/
// Coin Change


// Recursion

// class Solution {
// public:
//     int helper(int ind, int target, vector<int> &coins, vector<vector<int>> &dp) {
//         if (target == 0) return 0;
//         if (ind < 0) return INT_MAX;
//         if (dp[ind][target] != -1) return dp[ind][target];

//         int pick = INT_MAX;
//         if (coins[ind] <= target) pick = helper(ind, target - coins[ind], coins, dp);
//         if (pick != INT_MAX) pick++;
//         int notPick = helper(ind - 1, target, coins, dp);
//         return dp[ind][target] = min(notPick, pick);
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
//         int result = helper(n - 1, amount, coins, dp);
//         if (result == INT_MAX) result = -1;
//         return result;
//     }
// };


// Tabulation

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int> (amount + 1, INT_MAX));
//         for (int i = 0; i < n; i++) dp[i][0] = 0;

//         for (int i = 0; i <= amount; i++) {
//             if (i % coins[0] == 0) dp[0][i] = i / coins[0];
//         }

//         for (int ind = 1; ind < n; ind++) {
//             for (int target = 0; target <= amount; target++) {
//                 int pick = INT_MAX;
//                 if (coins[ind] <= target) pick = dp[ind][target - coins[ind]];
//                 if (pick != INT_MAX) pick++;

//                 int notPick = dp[ind - 1][target];
//                 dp[ind][target] = min(notPick, pick);
//             }
//         }

//         if (dp[n - 1][amount] == INT_MAX) return -1;
//         return dp[n - 1][amount];
//     }
// };


// Space Optimisation

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, INT_MAX - 1);
        prev[0] = 0;

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) prev[i] = i / coins[0];
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {
                int pick = INT_MAX;
                if (coins[ind] <= target) pick = 1 + prev[target - coins[ind]];
                int notPick = prev[target];
                prev[target] = min(notPick, pick);
            }
        }

        if (prev[amount] == INT_MAX - 1) return -1;
        return prev[amount];
    }
};
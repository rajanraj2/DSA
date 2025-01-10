// https://leetcode.com/problems/coin-change-ii/description/
// Coin Change II


// Recursion

// class Solution {
// public:
//     int helper(int ind, int target, vector<int> &coins, vector<vector<int>> &dp) {
//         if (target == 0) return 1;
//         if (ind == 0) return (target % coins[ind] == 0);
//         if (dp[ind][target] != -1) return dp[ind][target];

//         int notPick = helper(ind - 1, target, coins, dp);
//         int pick = 0;
//         if (coins[ind] <= target) pick = helper(ind, target - coins[ind], coins, dp);

//         return dp[ind][target] = notPick + pick;
//     } 

//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, (vector<int> (amount + 1, -1)));
//         return helper(n - 1, amount, coins, dp);
//     }
// };


// Tabulation - doesn't work

// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<long long>> dp(n, (vector<long long> (amount + 1, 0)));
//         for (int i = 0; i < n; i++) dp[i][0] = 1;
//         for (int target = 0; target <= amount; target++) {
//             if (target % coins[0] == 0) dp[0][target] = 1; 
//         }

//         for (int ind = 1; ind < n; ind++) {
//             for (int target = 0; target <= amount; target++) {
//                 long long notPick = dp[ind - 1][target];
//                 long long pick = 0;
//                 if (coins[ind] <= target) pick = dp[ind][target - coins[ind]];
//                 if (notPick + pick > INT_MAX) dp[ind][target] = INT_MAX;
//                 else dp[ind][target] = notPick + pick;
//             }
//         }
//         return (int)dp[n - 1][amount];
//     }
// };


// Space Optimisation

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int target = coin; target <= amount; target++) {
                dp[target] += dp[target - coin];
                if (dp[target] > INT_MAX) dp[target] = INT_MAX;
            }
        }

        return dp[amount];
    }
};

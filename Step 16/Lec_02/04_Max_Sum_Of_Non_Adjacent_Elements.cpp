// https://leetcode.com/problems/house-robber/description/
// house robber


// memoization

// class Solution {
// private:
//     int solve(vector<int> &nums, int i, vector<int> &dp) {
//         if (i < 0) return 0;
//         if (i == 0) return nums[i];
//         if (dp[i] != -1) return dp[i];
//         int pick = nums[i] + solve(nums, i - 2, dp);
//         int notpick = solve(nums, i - 1, dp);
//         return dp[i] = max(pick, notpick);
//     }

// public:
//     int rob(vector<int>& nums) {
//         vector<int> dp(nums.size(), -1);
//         return solve(nums, nums.size() - 1, dp);
//     }
// };


// tabulation

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 0);
//         for (int i = 0; i < n; i++) {
//             int pick = nums[i];
//             if (i >= 2) pick += dp[max(0, i - 2)];
//             int notpick = dp[max(0, i - 1)];
//             dp[i] = max(pick, notpick);
//         }
//         return dp[n - 1];
//     }
// };


// space optimization

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0, prev1 = nums[0]; 
        for (int i = 1; i < n; i++) {
            int pick = nums[i] + prev2;
            int notpick = prev1;
            prev2 = prev1;
            prev1 = max(pick, notpick);
        }
        return prev1;
    }
};
#include <bits/stdc++.h>
using namespace std;

// Alternate method 1 : memorisation
// class Solution {
// public:
//     int helper(vector<int> &nums, int n, vector<int> &dp) {
//         if (n < 0) return 0;
//         if (n == 0) return nums[0];
//         if (dp[n] != -1) return dp[n];
//         int incl = helper(nums, n-2, dp) + nums[n];
//         int excl = helper(nums, n-1, dp);
//         dp[n] = max(incl, excl);
//         return dp[n];
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1);
//         int ans = helper(nums, n - 1, dp);
//         return ans;
//     }
// };


// Alternate method 2 : tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        int incl, excl;
        for (int i=1; i < n; i++) {
            if (i-2 >= 0){incl = nums[i] + dp[i-2];}
            else incl = nums[i];
            excl = dp[i-1];
            dp[i] = max(incl, excl);
        }
        return dp[n-1];
    }
};


// Alternate method 3 : reduce space complexity to O(1)
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1);
//         dp[0] = nums[0];
//         int incl, excl;
//         for (int i=1; i < n; i++) {
//             if (i-2 >= 0){incl = nums[i] + dp[i-2];}
//             else incl = nums[i];
//             excl = dp[i-1];
//             dp[i] = max(incl, excl);
//         }
//         return dp[n-1];
//     }
// };

int main() {
    vector<int> v = {2, 7, 9, 3, 1};
    Solution s;
    cout << s.rob(v) << endl;
    return 0;
}
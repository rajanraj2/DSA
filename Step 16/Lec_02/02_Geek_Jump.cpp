// https://www.geeksforgeeks.org/problems/geek-jump/1
// Geek Jump


//  memoization

// class Solution {
//   private:
//     int solve(vector<int>& dp, vector<int>& height, int n) {
//         if (n == 0) return 0;
//         if (dp[n] != -1) return dp[n];
        
//         int one = solve(dp, height, n - 1) + abs(height[n] - height[n - 1]);
//         int two = INT_MAX;
//         if (n - 2 >= 0) two = solve(dp, height, n - 2) + abs(height[n] - height[n - 2]);
//         return dp[n] = min(one, two);
//     }
    
//   public:
//     int minimumEnergy(vector<int>& height, int n) {
//         // Code here
//         vector<int> dp(n + 1, -1);
//         return solve(dp, height, n - 1);
//     }
// };


// tabulation

// class Solution {
//   public:
//     int minimumEnergy(vector<int>& height, int n) {
//         // Code here
//         vector<int> dp(n + 1, -1);
//         dp[0] = 0;
//         for (int i = 1; i < n; i++) {
//             int one = dp[i - 1] + abs(height[i] - height[i - 1]);
//             int two = INT_MAX;
//             if (i > 1) two = dp[i - 2] + abs(height[i] - height[i - 2]);
//             dp[i] = min(one, two);
//         }
//         return dp[n - 1];
//     }
// };


// space optimised

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int prev1 = 0, prev2;
        for (int i = 1; i < n; i++) {
            int one = prev1 + abs(height[i] - height[i - 1]);
            int two = INT_MAX;
            if (i > 1) two = prev2 + abs(height[i] - height[i - 2]);
            prev2 = prev1;
            prev1 = min(one, two);
        }
        return prev1;
    }
};
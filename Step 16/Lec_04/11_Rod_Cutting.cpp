// https://www.geeksforgeeks.org/problems/rod-cutting0840/1
// Rod Cutting


// Memoization

// class Solution {
//   public:
//     int helper(int ind, int target, vector<int> &price, vector<vector<int>> &dp) {
//         if (ind < 0) return 0;
//         if (dp[ind][target] != -1) return dp[ind][target];
        
//         int notPick = helper(ind - 1, target, price, dp);
//         int pick = 0;
//         if (ind + 1 <= target) pick = price[ind] + helper(ind, target - ind - 1, price, dp);
//         return dp[ind][target] = max(notPick, pick);
//     }
    
//     int cutRod(vector<int> &price) {
//         // code here
//         int n = price.size();
//         vector<vector<int>> dp(n, vector<int> (n + 1, -1));
//         return helper(n - 1, n, price, dp);
//     }
// };


// Tabulation

// class Solution {
//   public:
//   int cutRod(vector<int> &price) {
//       int n = price.size();
//       vector<vector<int>> dp(n, vector<int> (n + 1, 0));
//       for (int i = 0; i <= n; i++) {
//           dp[0][i] = i * price[0];
//       }
      
//       for (int ind = 1; ind < n; ind++) {
//           for (int target = 0; target <= n; target++) {
//               int notPick = dp[ind - 1][target];
//               int pick = 0;
//               if (ind + 1 <= target) pick = price[ind] + dp[ind][target - ind - 1];
//               dp[ind][target] = max(notPick, pick);
//           }
//       }
//       return dp[n - 1][n];
//   }
// };


// Space Optimisation

class Solution {
  public:
  int cutRod(vector<int> &price) {
      int n = price.size();
      vector<int> prev(n + 1, 0);
      for (int i = 0; i <= n; i++) {
          prev[i] = i * price[0];
      }
      
      for (int ind = 1; ind < n; ind++) {
          for (int target = 0; target <= n; target++) {
              int notPick = prev[target];
              int pick = 0;
              if (ind + 1 <= target) pick = price[ind] + prev[target - ind - 1];
              prev[target] = max(notPick, pick);
          }
      }
      return prev[n];
  }
};

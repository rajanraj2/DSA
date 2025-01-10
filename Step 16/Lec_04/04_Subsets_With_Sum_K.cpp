// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
// Perfect Sum Problem


// class Solution {
//   public:
//     int helper(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
//         if (ind < 0) return (target == 0) ? 1 : 0;
//         if (dp[ind][target] != -1) return dp[ind][target];
        
//         int notPick = helper(ind - 1, target, arr, dp);
//         int pick = 0;
//         if (arr[ind] <= target) pick = helper(ind - 1, target - arr[ind], arr, dp);
//         return dp[ind][target] = pick + notPick;
//     }
    
//     int perfectSum(vector<int>& arr, int target) {
//         // code here
//         vector<vector<int>> dp(arr.size(), vector<int> (target + 1, -1));
//         return helper(arr.size() - 1, target, arr, dp);
//     }
// };


// Tabulation

// class Solution {
//   public:
//   int perfectSum(vector<int>& arr, int target) {
//       int n = arr.size();
//       vector<vector<int>> dp(n, vector<int> (target + 1, 0));
//       for (int i = 0; i < n; i++) dp[i][0] = 1;
//       if (arr[0] <= target) dp[0][arr[0]] = 1;
//       if (arr[0] == 0) dp[0][0] = 2;
      
//       for (int ind = 1; ind < arr.size(); ind++) {
//           for (int tar = 0; tar <= target; tar++) {
//               int notPick = dp[ind - 1][tar];
//               int pick = 0;
//               if (arr[ind] <= tar) pick = dp[ind - 1][tar - arr[ind]];
//               dp[ind][tar] = pick + notPick;
//           }
//       }
//       return dp[n - 1][target];
//   }
// };


// Space Optimisation

class Solution {
  public:
  int perfectSum(vector<int>& arr, int target) {
      int n = arr.size();
      vector<int> prev(target + 1, 00);
      prev[0] = 1;
      if (arr[0] <= target) prev[arr[0]] = 1;
      if (arr[0] == 0) prev[0] = 2;
      
      for (int ind = 1; ind < arr.size(); ind++) {
          vector<int> temp(target + 1, 0);
          temp[0] = 1;
          for (int tar = 0; tar <= target; tar++) {
              int notPick = prev[tar];
              int pick = 0;
              if (arr[ind] <= tar) pick = prev[tar - arr[ind]];
              temp[tar] = pick + notPick;
          }
          prev = temp;
      }
      return prev[target];
  }
};
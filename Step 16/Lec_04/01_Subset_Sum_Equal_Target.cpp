// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// Subset Sum Problem


// Recursion

// class Solution {
//   public:
//     bool helper(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
//         if (target == 0) return true;
//         if (ind < 0) return false;
//         if (dp[ind][target] != -1) return dp[ind][target];
        
//         bool notTake = helper(ind - 1, target, arr, dp);
        
//         bool take = false;
//         if (arr[ind] <= target) {
//             take = helper(ind - 1, target - arr[ind], arr, dp);
//         }
//         return dp[ind][target] = (notTake || take);
//     }
    
//     bool isSubsetSum(vector<int>& arr, int target) {
//         // code here
//         int n = arr.size();
//         vector<vector<int>> dp(n, vector<int> (target + 1, -1));
//         return helper(arr.size() - 1, target, arr, dp);
//     }
// };


// Tabulatin

// class Solution {
//   public:
//     bool isSubsetSum(vector<int>& arr, int target) {
//         // code here
//         int n = arr.size();
//         vector<vector<int>> dp(n, vector<int> (target + 1, 0));
//         for (int i = 0; i < n; i++) dp[i][0] = true;
//         if (arr[0] <= target) dp[0][arr[0]] = true; // didn't understand this line
        
//         for (int ind = 1; ind < n; ind++) {
//             for (int j = 0; j <= target; j++) { 
//                 bool notTake = dp[ind - 1][j];
//                 bool take = false;
//                 if (arr[ind] <= j) {
//                     take = dp[ind - 1][j - arr[ind]];
//                 }
//                 dp[ind][j] = (notTake || take);
//             }
//         }
//         return dp[n - 1][target];
//     }
// };


// Space Optimisation

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<int> prev(target + 1, 0), curr(target + 1, 0);
        prev[0] = true, curr[0] = true;
        if (arr[0] <= target) prev[arr[0]] = true; // didn't understand this line
        
        for (int ind = 1; ind < n; ind++) {
            for (int j = 0; j <= target; j++) { 
                bool notTake = prev[j];
                bool take = false;
                if (arr[ind] <= j) {
                    take = prev[j - arr[ind]];
                }
                curr[j] = (notTake || take);
            }
            prev = curr;
        }
        return prev[target];
    }
};

// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
// Knapsack with Duplicate Items


// Memoization

// class Solution {
//   public:
//     int helper(int ind, int w, vector<int>& val, vector<int>& wt, vector<vector<int>> &dp) {
//         if (ind < 0) return 0;
//         if (dp[ind][w] != -1) return dp[ind][w];
        
//         int notPick = helper(ind - 1, w, val, wt, dp);
//         int pick = INT_MIN;
//         if (wt[ind] <= w) pick = val[ind] + helper(ind, w - wt[ind], val, wt, dp);
//         return dp[ind][w] = max(notPick, pick);
//     }
    
//     int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
//         // code here
//         int n = val.size();
//         vector<vector<int>> dp(n, vector<int> (capacity + 1, -1));
//         return helper(n - 1, capacity, val, wt, dp);
//     }
// };


// Tabulation

// class Solution {
//   public:
//     int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
//         int n = val.size();
//         vector<vector<int>> dp(n, vector<int> (capacity + 1, 0));
//         for (int i = wt[0]; i <= capacity; i++) dp[0][i] = val[0] * (i / wt[0]);
        
//         for (int ind = 1; ind < n; ind++) {
//             for (int w = 0; w <= capacity; w++) {
//                 int notPick = dp[ind - 1][w];
//                 int pick = INT_MIN;
//                 if (wt[ind] <= w) pick = val[ind] + dp[ind][w - wt[ind]];
//                 dp[ind][w] = max(notPick, pick);
//             }
//         }
//         return dp[n - 1][capacity];
//     }
// };
  

// Space optimisation

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<int> prev(capacity + 1, 0);
        for (int i = wt[0]; i <= capacity; i++) prev[i] = val[0] * (i / wt[0]);
        
        for (int ind = 1; ind < n; ind++) {
            for (int w = 0; w <= capacity; w++) {
                int notPick = prev[w];
                int pick = INT_MIN;
                if (wt[ind] <= w) pick = val[ind] + prev[w - wt[ind]];
                prev[w] = max(notPick, pick);
            }
        }
        return prev[capacity];
    }
};

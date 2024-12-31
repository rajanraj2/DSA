// https://www.geeksforgeeks.org/problems/minimal-cost/1
// Minimal cost


class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            int minSteps = INT_MAX, jump = INT_MAX;
            for (int j = 1; j <= k; j++) {
                if (i >= j) jump = dp[i - j] + abs(arr[i] - arr[i - j]);
                minSteps = min(minSteps, jump);
            }
            dp[i] = minSteps;
        }
        return dp[n - 1];
    }
};
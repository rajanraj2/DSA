#include <bits/stdc++.h>
using namespace std;

// Alternate method 1 : memorisation
// class Solution {
// public:
//     int helper(vector<int> &cost, int n, int i, vector<int> &dp){
//         if (i == 0) return cost[0];
//         if (i == 1) return cost[1];
//         if (dp[i] != -1) return dp[i];
//         int result = cost[i] + min(helper(cost, n, i-1, dp), helper(cost, n, i-2, dp));
//         dp[i] = result;
//         return dp[i];
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n+1, -1);
//         int ans = min(helper(cost, n, n-1, dp), helper(cost, n, n-2, dp)); 
//         return ans;
//     }
// };


// Alternate method 2 : tabulation
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        int prev2 = cost[0];
        int prev1 = cost[1];
        int result;
        for (int i = 2; i < n; i++) {
            // dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
            result = min(prev1, prev2) + cost[i];
            prev2 = prev1;
            prev1 = result;
        }
        // return min(dp[n-1], dp[n-2]);
        return min(prev1, prev2);
    }
};

int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};
    cout << sol.minCostClimbingStairs(cost) << endl;
    return 0;
}
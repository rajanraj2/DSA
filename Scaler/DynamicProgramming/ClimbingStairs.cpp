#include <bits/stdc++.h>
using namespace std;

// Alternate method 1 : dynamic programming (memorisation)
// class Solution {
// public:
//     int helper(int n, int i, vector<int> &dp){
//         if (i == n) return 1;
//         if (i > n) return 0;
//         if (dp[i] != -1) return dp[i];
//         int result = helper(n, i+1, dp) + helper(n, i+2, dp);
//         dp[i] = result;
//         return dp[i];
//     }
//     int climbStairs(int n) {
//         vector<int> dp(n + 1, -1);
//         int ans = helper(n, 0, dp); 
//         return ans;
//     }
// };


// Alternate method 2 : dynamic programming (tabulation)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        if (n <= 2) return n;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// Alternate method 3 : fibonacci series
// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n <= 2) return n;
//         int a = 1, b = 2, c;
//         for (int i = 3; i <= n; i++) {
//             c = a + b;
//             a = b;
//             b = c;
//         }
//         return b;
//     }
// };


int main() {
    Solution sol;
    cout << sol.climbStairs(5) << endl;
    return 0;
}
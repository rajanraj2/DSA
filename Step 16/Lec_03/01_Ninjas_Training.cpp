// https://www.geeksforgeeks.org/problems/geeks-training/1
// Geek's Training


// recursion

// class Solution {
//   public:
//     int solve(vector<vector<int>>& arr, int day, int last, vector<vector<int>>& dp) {
//         if (day < 0) return 0;
//         int maxi = 0;
//         int ind = -1;
//         if (dp[day][last] != -1) return dp[day][last];
//         for (int i = 0; i < 3; i++) {
//             if (i != last) {
//                 int points = arr[day][i] + solve(arr, day - 1, i, dp);
//                 maxi = max(maxi, points);
//             }
//         }
//         return dp[day][last] = maxi;
//     }
    
//     int maximumPoints(vector<vector<int>>& arr, int n) {
//         // Code here
//         vector<vector<int>> dp(n, vector<int> (4, -1));
//         return solve(arr, n - 1, 3, dp);
//     }
// };


// tabulation

// class Solution {
//     public:
//         int maximumPoints(vector<vector<int>>& arr, int n) {
//             vector<vector<int>> dp(n, vector<int> (4, 0));
//             dp[0][0] = max(arr[0][1], arr[0][2]);
//             dp[0][1] = max(arr[0][0], arr[0][2]);
//             dp[0][2] = max(arr[0][0], arr[0][1]);
//             dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});
                
//             for (int day = 1; day < n; day++) {
//                 for (int last = 0; last < 4; last++) {
//                     dp[day][last] = 0;
//                     for (int i = 0; i < 3; i++) {
//                         if (i != last) {
//                             int point = arr[day][i] + dp[day - 1][i];
//                             dp[day][last] = max(dp[day][last], point);
//                         }
//                     }
//                 }
//             }
//             return dp[n - 1][3];
//         }
// };


// space optimisation

class Solution {
    public:
        int maximumPoints(vector<vector<int>>& arr, int n) {
            vector<int> dp(4, 0);
            dp[0] = max(arr[0][1], arr[0][2]);
            dp[1] = max(arr[0][0], arr[0][2]);
            dp[2] = max(arr[0][0], arr[0][1]);
            dp[3] = max({arr[0][0], arr[0][1], arr[0][2]});
                
            for (int day = 1; day < n; day++) {
                vector<int> temp(4, 0);
                for (int last = 0; last < 4; last++) {
                    temp[last] = 0;
                    
                    for (int i = 0; i < 3; i++) {
                        if (i != last) {
                            int point = arr[day][i] + dp[i];
                            temp[last] = max(temp[last], point);
                        }
                    }
                }
                dp = temp;
            }
            return dp[3];
        }
};
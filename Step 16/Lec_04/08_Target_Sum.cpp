// https://leetcode.com/problems/target-sum/
// Target Sum


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int diff = totalSum - target;
        if (diff < 0 || diff % 2) return 0;
        
        return perfectSum(nums, diff / 2);
    }

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prev(target + 1, 0);
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


// class Solution {
// public:
//     int helper(int ind, int sum, int target, vector<int> &nums, unordered_map<string, int> &mpp) {
//         if (ind < 0) return (target == sum);
//         string key = to_string(ind) + "," + to_string(sum);
//         if (mpp.find(key) != mpp.end()) return mpp[key];

//         int plus = helper(ind - 1, sum + nums[ind], target, nums, mpp);
//         int minus = helper(ind - 1, sum - nums[ind], target, nums, mpp);
//         return mpp[key] = plus + minus;
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         unordered_map<string, int> mpp;
//         return helper(n - 1, 0, target, nums, mpp);
//     }
// };
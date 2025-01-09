// https://leetcode.com/problems/partition-equal-subset-sum/
// Partition Equal Subset Sum


class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int target) {
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

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        return isSubsetSum(nums, sum / 2);
    }
};
// https://leetcode.com/problems/house-robber-ii/description/
// House Robber II


class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        int n = nums.size();
        int prev2 = 0, prev1 = 0; 
        for (int i = start; i <= end; i++) {
            int pick = nums[i] + prev2;
            int notpick = prev1;
            prev2 = prev1;
            prev1 = max(pick, notpick);
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int a = solve(nums, 0, n - 2);
        int b = solve(nums, 1, n - 1);
        return max(a, b);
    }
};
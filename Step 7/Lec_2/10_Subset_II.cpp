// https://leetcode.com/problems/subsets-ii/description/
// Subset II


class Solution {
private:
    void helper(vector<vector<int>>& result, vector<int>& ans, vector<int>& nums, int start) {
        result.push_back(ans);
        for (int j = start; j < nums.size(); j++) {
            if (j > start && nums[j] == nums[j - 1]) continue;
            ans.push_back(nums[j]);
            helper(result, ans, nums, j + 1);
            ans.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> ans;
        helper(result, ans, nums, 0);
        return result;
    }
};
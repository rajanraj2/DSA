// https://leetcode.com/problems/combination-sum-ii/
// Combination Sum II


class Solution {
private:
    void helper(vector<int>& candidates, int target, vector<int>& arr, vector<vector<int>>& result, int start) {
        if (target == 0) {
            result.push_back(arr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break;

            arr.push_back(candidates[i]);
            helper(candidates, target - candidates[i], arr, result, i + 1);
            arr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> arr;
        helper(candidates, target, arr, result, 0);
        return result;
    }
};
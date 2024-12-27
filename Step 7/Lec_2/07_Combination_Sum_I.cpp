// https://leetcode.com/problems/combination-sum/
// Combination Sum


class Solution {
private:
    void helper(int i, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& result) {
        if (i >= candidates.size()) {
            if (target == 0) result.push_back(temp);
            return;
        } 
        if (candidates[i] <= target) {
            temp.push_back(candidates[i]);
            helper(i, candidates, target - candidates[i], temp, result);
            temp.pop_back();
        }
        helper(i + 1, candidates, target, temp, result);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        helper(0, candidates, target, temp, result);
        return result;
    }
};
// https://www.geeksforgeeks.org/problems/subset-sums2234/1
// Subset Sums

class Solution {
  private:
    void helper(vector<int>& arr, vector<int>& result, int i, int sum) {
        if (i >= arr.size()) {
            result.push_back(sum);
            return;
        }
        helper(arr, result, i + 1, sum + arr[i]);
        helper(arr, result, i + 1, sum);
    }
    
  public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> result;
        helper(arr, result, 0, 0);
        return result;
    }
};
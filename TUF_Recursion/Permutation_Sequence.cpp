// https://leetcode.com/problems/permutation-sequence/description/
// Permutation Sequence


class Solution {
public:
    string getPermutation(int n, int k) {
        string result = "";
        vector<int> arr;
        int fact = 1;
        for (int i = 1; i < n; i++) {
            arr.push_back(i);
            fact *= i;
        }
        arr.push_back(n);
        k = k - 1;
        while (true) {
            result += to_string(arr[k / fact]);
            arr.erase(arr.begin() + k / fact);
            if (arr.size() == 0) break;
            k = k % fact;
            fact /= arr.size();
        }
        return result;        
    }
};
// https://leetcode.com/problems/palindrome-partitioning/
// Palindrome Partitioning


class Solution {
private:
    void solve(vector<vector<string>>& result, vector<string>& ans, string& s, int ind) {
        if (ind >= s.size()) {
            result.push_back(ans);
            return;
        }

        for (int i = ind; i < s.size(); i++) {
            if (palindrome(s, ind, i)) {
                ans.push_back(s.substr(ind, i - ind + 1));
                solve(result, ans, s, i + 1);
                ans.pop_back();
            }
        }
    }

    bool palindrome(string& s, int start, int end) {
        while (start <= end) if (s[start++] != s[end--]) return false;
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> ans;
        solve(result, ans, s, 0);
        return result;
    }
};
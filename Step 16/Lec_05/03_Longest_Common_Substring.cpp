// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
// Longest Common Substring


class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size(), m = s2.size(), result = 0;
        vector<int> prev(m + 1, 0), cur(m + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) cur[j] = 1 + prev[j - 1];
                else cur[j] = 0;
                result = max(result, cur[j]);
            }
            prev = cur;
        }
        return result;
    }
};
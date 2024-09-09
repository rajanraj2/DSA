// Link - https://leetcode.com/problems/remove-k-digits/
// Remove K Digits


class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        string result = "";
        if (k >= n) return "0";

        for (char it : num) {
            while (k && !st.empty() && st.top() - '0' > it - '0') {
                st.pop();
                k--;
            }
            st.push(it);
        }

        while (k--) {
            if (!st.empty()) st.pop();
        }

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        int s = result.size();
        for (int i = s - 1; i >= 0; i--) {
            if (result[i] == '0') result.pop_back();
            else break;
        }
        cout << result << endl;

        reverse(result.begin(), result.end());
        if (result.size() == 0) return "0";
        return result;
    }
};
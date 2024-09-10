// Link - https://leetcode.com/problems/maximal-rectangle/description/
// Maximal Rectangle


class Solution {
private:
    int histogram(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, element * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int element = heights[st.top()];
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, element * (nse - pse - 1));
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> height(n, vector<int> (m));
        int maxArea = 0;

        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '1') sum++;
                else sum = 0;
                height[i][j] = sum;
            }
        }

        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, histogram(height[i]));
        }

        return maxArea;
    }
};
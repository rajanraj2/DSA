// Link - https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// Largest Rectangle in Histogram


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
};




// Alternate method 

// class Solution {
// private:
//     void findNSE(vector<int> arr, vector<int>& nse, int n) {
//         stack<int> st;
//         for (int i = n - 1; i >= 0; i--) {
//             while (!st.empty() && arr[st.top()] > arr[i]) {
//                 st.pop();
//             }
//             nse[i] = st.empty() ? n : st.top();
//             st.push(i);
//         }
//     }

//     void findPSEE(vector<int> arr, vector<int>& pse, int n) {
//         stack<int> st;
//         for (int i = 0; i < n; i++) {
//             while (!st.empty() && arr[st.top()] >= arr[i]) {
//                 st.pop();
//             }
//             pse[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }
//     } 

// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int maxi = 0;
//         vector<int> pse(n), nse(n);
//         findNSE(heights, nse, n);
//         findPSEE(heights, pse, n);

//         for (int i = 0; i < n; i++) {
//             int width = (nse[i] - pse[i] - 1);
//             maxi = max(maxi, heights[i] * width);
//         }

//         return maxi;
//     }
// };
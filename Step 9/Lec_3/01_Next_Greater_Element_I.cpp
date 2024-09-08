// Link - https://leetcode.com/problems/next-greater-element-i/
// Next Greater Element I


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> result(nums1.size());
        stack<int> st;
        unordered_map<int, int> mpp;

        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                mpp[nums2[i]] = -1;
            }
            else {
                while (!st.empty() && st.top() <= nums2[i]) {
                    st.pop();
                }
                if (!st.empty()) mpp[nums2[i]] = st.top();
                else mpp[nums2[i]] = -1;
            }
            st.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {
            result[i] = mpp[nums1[i]];
        }

        return result;
    }
};
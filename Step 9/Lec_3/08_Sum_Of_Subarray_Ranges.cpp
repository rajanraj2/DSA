// Link - https://leetcode.com/problems/sum-of-subarray-ranges/
// Sum of Subarray Ranges


class Solution {
private:
    void findNSE(vector<int>& nums, int n, vector<int>& nse) {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            nse[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
    }

    void findPSEE(vector<int>& nums, int n, vector<int>& pse) {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
    }

    void findNGE(vector<int>& nums, int n, vector<int>& nge) {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            nge[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
    }

    void findPGEE(vector<int>&   nums, int n, vector<int>& pge) {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            pge[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long lTotal = 0, sTotal = 0;
        vector<int> nse(n), pse(n), nge(n), pge(n);
        findNSE(nums, n, nse);
        findPSEE(nums, n, pse);
        findNGE(nums, n, nge);
        findPGEE(nums, n, pge);

        for (int i = 0; i < n; i++) {
            int left = 
            lTotal += (long long)nums[i] * (i - pge[i]) * (nge[i] - i);
            sTotal += (long long)nums[i] * (i - pse[i]) * (nse[i] - i);  
        }

        return lTotal - sTotal;
    }
};
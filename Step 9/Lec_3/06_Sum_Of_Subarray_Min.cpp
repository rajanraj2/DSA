// Link - https://leetcode.com/problems/sum-of-subarray-minimums/
// Sum of Subarray Minimums


class Solution {
private:
    void findPSEE(vector<int> arr, int n, vector<int>& pse) {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void findNSE(vector<int> arr, int n, vector<int>& nse) {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        long long total = 0;
        int n = arr.size(), mod = 1e9 + 7;
        vector<int> pse(n), nse(n);
        findPSEE(arr, n, pse);
        findNSE(arr, n, nse);

        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            // int right = nse[i] - i;
            // int left = (pse[i] == -1) ? (i + 1) : (i - pse[i]);
            int right = (nse[i] == -1) ? (n - i) : (nse[i] - i);
            total = (total + ((long long)left * right % mod * arr[i] % mod)) % mod;
        }

        return int(total);
    }
};




// Alternate method

// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int total = 0;
//         int n = arr.size();
//         int mod = 1e9 + 7;

//         for (int i = 0; i < n; i++) {
//             int mini = arr[i];
//             for (int j = i; j < n; j++) {
//                 mini = min(mini, arr[j]);
//                 total = (total + (mini % mod)) % mod;
//             }
//         }
        
//         return total;
//     }
// };
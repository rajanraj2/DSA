// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
// Minimum Number of Days to Make m Bouquets


class Solution {
private: 
    int possible(vector<int>& bloomDay, int m, int k, int mid, int n) {
        int ans = 0, count = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid) count++;
            else {
                ans += count / k;
                count = 0;
            }
            if (ans > m) return ans;
        }
        ans += count / k;
        return ans;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int result = -1;
        int n = bloomDay.size();
        if (n / m < k) return result;
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = possible(bloomDay, m, k, mid, n);
            if (val >= m) {
                result = mid;
                right = mid - 1;
            } 
            else left = mid + 1;
        }
        return result;
    }
};
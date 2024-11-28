// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
// Find the Smallest Divisor Given a Threshold


class Solution {
private:
    int possible(vector<int>& nums, int threshold, int mid) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += nums[i] / mid;
            if (nums[i] % mid > 0) ans++; 
        }
        if (ans <= threshold) return true;
        else return false;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(nums, threshold, mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};
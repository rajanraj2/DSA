// https://leetcode.com/problems/find-peak-element/description/
// Find Peak Element


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        int left = 1, right = n - 2;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            else if (nums[mid - 1] < nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};
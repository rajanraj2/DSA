// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Find Minimum in Rotated Sorted Array


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[left] <= nums[right]) {
                result = min(result, nums[left]);
                break;
            }
            if (nums[left] <= nums[mid]) {
                result = min(result, nums[left]);
                left = mid + 1;
            }
            else {
                result = min(result, nums[mid]);
                right = mid - 1;
            }
        }
        return result;
    }
};
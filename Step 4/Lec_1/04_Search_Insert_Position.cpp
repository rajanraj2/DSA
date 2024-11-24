// https://leetcode.com/problems/search-insert-position/
// Search Insert Position


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};


// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int n = nums.size();
//         int result = n;
//         int left = 0, right = n - 1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] <= target) {
//                 result = mid;
//                 left = mid + 1;
//             }
//             else right = mid - 1;
//         }
//         if (nums[0] >= target) return 0;
//         if (result >= n) return result;
//         if (nums[result] == target) return result;
//         return (result + 1);
//     }
// };
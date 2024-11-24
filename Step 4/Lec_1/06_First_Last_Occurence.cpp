// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Find First and Last Position of Element in Sorted Array


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (lb == nums.size() || nums[lb] != target) return {-1, -1};
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return {lb, ub - 1};
    }
};


// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size();
//         int left = 0, right = n - 1;
//         vector<int> result = {-1, -1};
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] >= target) {
//                 if (nums[mid] == target) result[0] = mid;
//                 right = mid - 1;
//             }
//             else left = mid + 1;
//         }
//         if (result[0] == -1) return result;

//         left = 0;
//         right = n - 1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] <= target) {
//                 if (nums[mid] == target) result[1] = mid;
//                 left = mid + 1;
//             }
//             else right = mid - 1;
//         }
//         return result;
//     }
// };


// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size();
//         int left = 0, right = n - 1;
//         vector<int> result = {-1, -1};
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] == target) {
//                 int mid2 = mid;
//                 while (mid >= 0 && nums[mid] == target) result[0] = mid--;
//                 while (mid2 < n && nums[mid2] == target) result[1] = mid2++;
//                 break;
//             } 
//             else if (nums[mid] > target) right = mid - 1;
//             else left = mid + 1;
//         }
//         return result;
//     }
// };
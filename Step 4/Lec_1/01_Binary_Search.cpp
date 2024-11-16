// https://leetcode.com/problems/binary-search/
// Binary Search

class Solution {
private:
    int helper(vector<int>& nums, int low, int high, int target) {
        if (high < low) return -1;
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
        return helper(nums, low, high, target);
    }

public:
    int search(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size() - 1, target);
    }
};


// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int low = 0, high = nums.size() - 1;

//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (nums[mid] == target) return mid;
//             else if (target > nums[mid]) low = mid + 1;
//             else high = mid - 1;
//         }

//         return -1;
//     }
// };
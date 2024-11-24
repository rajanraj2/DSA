// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
// Number of Occurrences


// class Solution {
//   public:
//     int countFreq(vector<int>& nums, int target) {
//         // code here
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
//         if (result[0] == -1) return 0;
        
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
//         return result[1] - result[0] + 1;
//     }
// };


class Solution {
  public:
    int countFreq(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (lb == nums.size() || nums[lb] != target) return 0;
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return ub - lb;
    }
};

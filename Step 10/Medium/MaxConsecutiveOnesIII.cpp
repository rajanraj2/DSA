// Link - https://leetcode.com/problems/max-consecutive-ones-iii/
// Max Consecutive Ones III

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int zero_count = 0;
        int result = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) zero_count++;

            if (zero_count > k) {
                if (nums[left] == 0) {
                    zero_count--;
                }
                left++;
            }

            if (zero_count <= k) result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};


// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int left = 0, right = 0;
//         int zero_count = 0;
//         int result = 0;

//         while (right < nums.size()) {
//             if (nums[right] == 0) zero_count++;

//             while (zero_count > k) {
//                 if (nums[left] == 0) {
//                     zero_count--;
//                 }
//                 left++;
//             }

//             result = max(result, right - left + 1);
//             right++;
//         }
//         return result;
//     }
// };


// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count0 = 0, length = 0, result = 0;
//         int index0;
//         for (int i  = 0; i < n; i++) {
//             int start = i;
//             if ((nums[i] == 0) && (count0 < k)) {
//                 if (count0 == 1) start = i;
//                 count0++;
//                 length++;
//             }
//             else if (nums[i] == 1) {
//                 length++;
//             }
//             else {
//                 if (count0 > 0) i = start;
//                 length = 0;
//                 count0 = 0;
//             }
//             result = max(result, length);
//         }
//         return result;
//     }
// };
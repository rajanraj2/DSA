// https://leetcode.com/problems/kth-missing-positive-number/description/
// Kth Missing Positive Number


// Brute Force

// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         for (auto it : arr) {
//             if (it <= k) k++;
//             else return k;
//         }
//         return k;
//     }
// };


// Using binary search

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = arr[mid] - mid - 1;
            if (val < k) left = mid + 1;
            else right = mid - 1;
        }
        return left + k;
    }
};

// ans = arr[right] + more
// arr[right] + (k - missing)
// arr[right] + k - (arr[right] - right - 1)
// k + right + 1
// k + left
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// Median of Two Sorted Arrays


// Binary Search

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n1;
        int n = n1 + n2;
        int left = (n + 1) / 2;

        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];
            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) return max(l1, l2); 
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return 0;
    }
};


// Optimised Space

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int i = 0, j = 0, index = 0;
//         int n = nums1.size(), m = nums2.size();
//         double ind1el = -1, ind2el = -1;
//         int ind2 = (n + m) / 2;
//         int ind1 = ind2 - 1;

//         while (i < n && j < m) {
//             if (ind1el != -1 && ind2el != -1) break;
//             if (nums1[i] <= nums2[j]) {
//                 if (index == ind1) ind1el = nums1[i];
//                 if (index == ind2) ind2el = nums1[i];
//                 index++;
//                 i++;
//             }
//             else {
//                 if (index == ind1) ind1el = nums2[j];
//                 if (index == ind2) ind2el = nums2[j];
//                 index++;
//                 j++;
//             }
//         }
//         while (i < n) {
//             if (ind1el != -1 && ind2el != -1) break;
//             if (index == ind1) ind1el = nums1[i];
//             if (index == ind2) ind2el = nums1[i];
//             index++;
//             i++;
//         }
//         while (j < m) {
//             if (ind1el != -1 && ind2el != -1) break;
//             if (index == ind1) ind1el = nums2[j];
//             if (index == ind2) ind2el = nums2[j];
//             index++;
//             j++;
//         }

//         if ((n + m) % 2 != 0) return ind2el;
//         return (ind1el + ind2el) / 2.0;
//     }
// };


// Brute Force

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int i = 0, j = 0, index = 0;
//         int n = nums1.size(), m = nums2.size();
//         vector<int> arr(n + m);
//         bool flag = false;
//         if ((n + m) % 2 == 0) flag = true;
//         double result;

//         while (i < n && j < m) {
//             if (nums1[i] <= nums2[j]) arr[index++] = nums1[i++];
//             else arr[index++] = nums2[j++]; 
//         }
//         while (i < n) arr[index++] = nums1[i++];
//         while (j < m) arr[index++] = nums2[j++];

//         int mid = (n + m + 1) / 2;
//         if (flag) result = (double)(arr[mid] + arr[mid - 1]) / (double)2;
//         else result = arr[mid - 1];
        
//         return result;
//     }
// };
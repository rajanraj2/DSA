#include <bits/stdc++.h>
using namespace std;

// Alternate method 1 : with extra space
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int left = 0, right = 0, index = 0;
//         vector<int> arr(n + m, 0);
//         while (left < m && right < n){
//             if (nums1[left] <= nums2[right]) {
//                 arr[index] = nums1[left];
//                 left++;
//                 index++;
//             }
//             else {
//                 arr[index] = nums2[right];
//                 right++;
//                 index++;
//             }
//         }
//         while (left < m) {
//             arr[index++] = nums1[left++];
//         }
//         while (right < n) {
//             arr[index++] = nums2[right++];
//         }
//         for (int i = 0; i < n + m; i++) {
//             if (i < m) nums1[i] = arr[i];
//             else nums1[i] = arr[i];
//         }
//     }
// };


// Alternate method 2 : optimal 1
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int left = m - 1;
//         int right = 0;
//         while (left >= 0 && right < n) {
//             if (nums1[left] > nums2[right]) {
//                 swap(nums1[left], nums2[right]);
//                 left--; right++;
//             }
//             else {
//                 break;
//             }
//         }
//         sort(nums1.begin(), nums1.begin() + m);
//         sort(nums2.begin(), nums2.end());
//         for (int i = m + n - 1; i >= m; i--) {
//             nums1[i] = nums2[i - m];    
//         }
//     }
// };


// Alternate method 3 : optimal 2
class Solution {
public:
    void swapIfGreater(vector<int>& nums1, int ind1, vector<int>& nums2, int ind2){
        if (nums1[ind1] > nums2[ind2]) {
            swap(nums1[ind1], nums2[ind2]);
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = (m + n);
        int gap = (len / 2) + (len % 2);
        while (gap > 0) {
            int left = 0;
            int right = left + gap;
            while (right < len) {
                // arr 1 and arr 2
                if (left < m && right >= m) {
                    swapIfGreater(nums1, left, nums2, right - m);
                }
                // arr 2 and arr 2
                else if (left >= m) {
                    swapIfGreater(nums2, left - m, nums2, right - m);
                }
                // arr 1 and arr 1
                else {
                    swapIfGreater(nums1, left, nums1, right);
                }
                left++; right++;
            }
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
        for (int i = m + n - 1; i >= m; i--) {
            nums1[i] = nums2[i - m];
        }
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    s.merge(nums1, 3, nums2, 3);
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    return 0;
}
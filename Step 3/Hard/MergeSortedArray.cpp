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
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1;
        int right = 0;
        while (left >= 0 && right < n) {
            if (nums1[left] > nums2[right]) {
                swap(nums1[left], nums2[right]);
                left--; right++;
            }
            else {
                break;
            }
        }
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());
        for (int i = m + n - 1; i >= m; i--) {
            nums1[i] = nums2[i - m];    
        }
    }
};

// Alternate method 3 : optimal 2

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
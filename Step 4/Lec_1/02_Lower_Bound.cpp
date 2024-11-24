// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%253BbatchId=154
// Floor in a Sorted Array


// class Solution {
//   public:

//     int findFloor(vector<int>& arr, int k) {

//         // Your code here
//         int lb = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
//         if (lb == 0 && arr[lb] > k) return -1;
//         if (lb == arr.size() || arr[lb] > k) lb--;
//         return lb;
//         int n = arr.size(), result = -1;
//         int left = 0, right = n - 1;
        
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (arr[mid] <= k) {
//                 result = mid;
//                 left = mid + 1;
//             }
//             else right = mid - 1;
//         }
//         return result;
//     }
// };


// STL method 

class Solution {
  public:
    int findFloor(vector<int>& arr, int k) {
        int lb = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
        if (lb == 0 && arr[lb] > k) return -1;
        if (lb == arr.size() || arr[lb] > k) lb--;
        return lb;
    }
};

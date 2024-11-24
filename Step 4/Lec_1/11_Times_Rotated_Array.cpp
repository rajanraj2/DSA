// https://www.geeksforgeeks.org/problems/rotation4723/1
// Find kth Rotation in a sorted array


class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int left = 0, right = n - 1;
        int result = INT_MAX, index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[left] <= arr[right]) {
                if (arr[left] <= result) {
                    result = arr[left];
                    index = left;
                }
                break;
            }
            if (arr[left] <= arr[mid]) {
                if (arr[left] <= result) {
                    result = arr[left];
                    index = left;
                }
                left = mid + 1;
            }
            else {
                if (arr[mid] <= result) {
                    result = arr[mid];
                    index = mid;
                }
                right = mid - 1;
            }
        }
        return index;
    }
};

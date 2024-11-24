// https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1
// Ceil The Floor


class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        vector<int> result = {-1, -1};
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= x) {
                result[0] = arr[mid];
                left = mid + 1;
            }
            else right = mid - 1;
        }
        left = 0;
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= x) {
                result[1] = arr[mid];
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return result;
    }
};
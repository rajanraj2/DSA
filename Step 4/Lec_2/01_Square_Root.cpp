// https://www.geeksforgeeks.org/problems/square-root/0
// Square Root


class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int left = 1, right = n;
        int result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid * mid == n) {
                result = mid;
                break;
            }
            else if (mid * mid > n) right = mid - 1;
            else {
                result = mid;
                left = mid + 1;
            }
        }
        return result;
    }
};
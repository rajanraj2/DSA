// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
// Find Nth root of M


class Solution {
  private:
    // TC : O(n)
    int helper(int mid, int n, int m) {
        int val = 1;
        for (int i = 0; i < n; i++) {
            val *= mid;
            if (val > m) return val; // solves multiplication overflow issue
        }
        return val;
    }
    
    // TC : O(log(n))
    // int power(int mid, int n) {
    //     long long ans = 1;
    //     while (n > 0) {
    //         if (n % 2 == 1) {
    //             ans = ans * mid;
    //             n = n - 1;
    //         }
    //         else {
    //             mid = mid * mid;
    //             n = n / 2;
    //         }
    //     }
    //     return ans;
    // }
    
  public:
    int nthRoot(int n, int m) {
        int left = 1, right = m;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = helper(mid, n, m);
            if (val == m) return mid;
            else if (val < m) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};
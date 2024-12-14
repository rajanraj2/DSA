// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
// Matrix in row-wise sorted Matrix


class Solution {
  private:
    // count numbers less than or equal to a given number / upper bound
    int countSmallEqual(vector<vector<int>>& mat, int n, int m, int x) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int left = 0, right = m - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (mat[i][mid] <= x) left = mid + 1;
                else right = mid - 1;
            }
            count += left;
        }
        return count;
    }
    
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }
        
        int req = (n * m) / 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int smallEqual = countSmallEqual(mat, n, m, mid);
            if (smallEqual <= req) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

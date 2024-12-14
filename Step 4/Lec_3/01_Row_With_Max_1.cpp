// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
// Row with max 1s


class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size(), m = arr[0].size();
        int result = 0, ans = -1, prev = 0;
        for (int i = 0; i < n; i++) {
            prev = result;
            int left = 0, right = m - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[i][mid] == 0) left = mid + 1;
                else right = mid - 1;
            }
            result = max(result, m - left);
            if (result > prev) ans = i;
        }
        return ans;
    }
};
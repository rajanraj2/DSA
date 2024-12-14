// https://leetcode.com/problems/search-a-2d-matrix-ii/description/
// Search in a 2D matrix II


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m - 1;
        while (true) {
            if (row >= n || col < 0) break;
            if (target == matrix[row][col]) return true;
            else if (matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};
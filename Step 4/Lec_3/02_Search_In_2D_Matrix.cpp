// https://leetcode.com/problems/search-a-2d-matrix/
// Search in a 2D Matrix


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = (n * m) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid / m][mid % m] > target) right = mid - 1;
            else if (matrix[mid / m][mid % m] < target) left = mid + 1;
            else return true; 
        }
        return false;
    }
};


// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n = matrix.size(), m = matrix[0].size();
//         int left = 0, right = n - 1;

//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (matrix[mid][0] > target) right = mid - 1;
//             else if (matrix[mid][m - 1] < target) left = mid + 1;
//             else {
//                 int l = 0, r = m - 1;
//                 while (l <= r) {
//                     int m = l + (r - l) / 2;
//                     if (matrix[mid][m] < target) l = m + 1;
//                     else if (matrix[mid][m] > target) r = m - 1;
//                     else return true;
//                 }
//                 return false;
//             }
//         }
//         return false;
//     }
// };
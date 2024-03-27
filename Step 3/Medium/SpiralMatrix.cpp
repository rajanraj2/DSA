#include <bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>&MATRIX) {
    int n = MATRIX.size();
    int m = MATRIX[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> result;
    while (top <= bottom && left <= right) {
        for (int i=left; i<=right; i++) {
            result.push_back(MATRIX[top][i]);
        }
        top++;
        for (int i=top; i<=bottom; i++) {
            result.push_back(MATRIX[i][right]);
        }
        right--;
        if (top <= bottom) {
            for (int i=right; i>=left; i--) {
                result.push_back(MATRIX[bottom][i]);
            }
            bottom--;
        }
        if (left <= right) {
            for (int i=bottom; i>=top; i--) {
                result.push_back(MATRIX[i][left]);
            }
            left++;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> MATRIX = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> result = spiralMatrix(MATRIX);
    for (int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
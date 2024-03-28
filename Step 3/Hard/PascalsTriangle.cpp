#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for (int col = 1; col < row; col++) {
            ans *= (row - col);
            ans /= col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> ans = sol.generate(5);
    for (auto row : ans) {
        for (int col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}
// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// Rat in a Maze Problem - I


class Solution {
  private:
    void solve(vector<vector<int>>& mat, vector<string>& result, string& s, 
    vector<vector<int>>& visited, int i, int j, int row[], int col[], string& dir) {
        if (i == mat.size() - 1 && j == mat[0].size() - 1) {
            result.push_back(s);
            return;
        }
        
        for (int k = 0; k < 4; k++) {
            int nrow = i + row[k];
            int ncol = j + col[k];
            if (nrow >= 0 && nrow < mat.size() && ncol >= 0 && ncol < mat[0].size() &&
            visited[nrow][ncol] == 0 && mat[nrow][ncol] == 1) {
                s += dir[k];
                visited[nrow][ncol] = 1;
                solve(mat, result, s, visited, nrow, ncol, row, col, dir);
                visited[nrow][ncol] = 0;
                s.pop_back();
            }
        } 
    }
    
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        vector<vector<int>> visited(mat.size(), vector<int> (mat[0].size(), 0));
        vector<string> result;
        string s;
        if (mat[0][0] == 0 || mat[mat.size() - 1][mat[0].size() - 1] == 0) return result;
        visited[0][0] = 1;
        int row[4] = {1, 0, -1, 0};
        int col[4] = {0, 1, 0, -1};
        string dir = "DRUL";
        solve(mat, result, s, visited, 0, 0, row, col, dir);
        return result;
    }
};
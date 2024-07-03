// Link - https://leetcode.com/problems/flood-fill/
// Flood Fill

// T.C. - O(n*m)


class Solution {
private :
    void dfs(int row, int col, vector<vector<int>>& result, vector<vector<int>>& image, int color, int delrow[], int delcol[], int iniColor){
        result[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && result[nrow][ncol] != color) {
                dfs(nrow, ncol, result, image, color, delrow, delcol, iniColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> result = image;
        int delrow[] = {1, 0, -1, 0}; 
        int delcol[] = {0, 1, 0, -1};
        dfs(sr, sc, result, image, color, delrow, delcol, iniColor);
        return result;
    }
};


// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
// M Coloring Problem


class Solution {
  private:
    bool isSafe(vector<pair<int, int>>& edges, vector<int>& color, int col, int vertex) {
        for (auto edge : edges) {
            if ((edge.first == vertex && color[edge.second] == col) || 
            (edge.second == vertex && color[edge.first] == col)) return false; 
        }
        return true;
    }
    
    bool solve(int v, vector<pair<int, int>>& edges, int m, vector<int>& color, int ind) {
        if (ind >= v) return true;
        
        for (int i = 1; i <= m; i++) {
            if (isSafe(edges, color, i, ind)) {
                color[ind] = i;
                if (solve(v, edges, m, color, ind + 1)) return true;
                color[ind] = 0;
            }
        }
        return false;
    }
    
  public:
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<int> color(v, 0);
        return solve(v, edges, m, color, 0);
    }
};
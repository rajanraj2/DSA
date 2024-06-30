// Link - https://www.geeksforgeeks.org/problems/number-of-provinces/1
// Number of Provinces


class Solution {
  private :
    void dfs(int node, vector<int>& visited, vector<vector<int>>& arr) {
        visited[node] = 1;
        for (auto it : arr[node]) {
            if (!visited[it]) {
                dfs(it, visited, arr);
            }
        }
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        // convert matrix to adjacency list
        vector<vector<int>> arr(V);
        for (int i = 0; i < adj.size(); i++) {
            for (int j = 0; j < adj[0].size(); j++) {
                if (adj[i][j] == 1 && i != j) {
                    arr[i].push_back(j);
                    arr[j].push_back(i);
                }
            }
        }
        
        int count = 0;
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                dfs(i, visited, arr);
                count++;
            }
        }
        
        return count;
    }
};
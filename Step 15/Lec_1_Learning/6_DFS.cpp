// Link - https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  private :
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &result) {
        vis[node] = 1;
        result.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, result);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int start = 0;
        vector<int> vis(V,0);
        vis[0] = 1;
        vector<int> result;
        dfs(start, adj, vis, result);
        return result;
    }
};
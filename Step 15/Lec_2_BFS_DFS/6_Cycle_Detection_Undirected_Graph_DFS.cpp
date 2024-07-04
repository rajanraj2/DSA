// Link - https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Undirected Graph Cycle


class Solution {
  private :
    bool dfs(int node, int parent, vector<int> adj[], int vis[]) {
        vis[node] = 1;
        for (auto adjacentNode : adj[node]) {
            if (!vis[adjacentNode]) {
                if (dfs(adjacentNode, node, adj, vis) == true) {
                    return true;
                }
            }
            else if (parent != adjacentNode) {
                return true;
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis) == true) return true;
            }
        }
        return false;
    }
};
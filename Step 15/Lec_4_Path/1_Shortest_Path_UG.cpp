// Link - https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
// Shortest Path in Undirected Graph having unit distances


class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> distance(N, INT_MAX);
        distance[src] = 0;
        queue<int> q;
        q.push(src);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto it : adj[node]) { 
                if (distance[node] + 1 < distance[it]) {
                    distance[it] = distance[node] + 1;
                    q.push(it);
                }
            }
        }
        vector<int> result(N, -1);
        for (int i = 0; i < N; i++) {
            if (distance[i] != INT_MAX) {
                result[i] = distance[i];
            }
        }
        
        return result;
    }
};
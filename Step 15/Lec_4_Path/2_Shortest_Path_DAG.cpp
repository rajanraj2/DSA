// Link - https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// Shortest Path in Directed Acyclic Graph


class Solution {
  private:
     void topoSort(int node, vector<int>& vis, vector<pair<int, int>> adj[], stack<int>& st) {
         vis[node] = 1;
         for (auto it : adj[node]) {
             int v = it.first;
             if (!vis[v]) {
                 topoSort(v, vis, adj, st);
             }
         }
         st.push(node);
     }
     
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<pair<int, int>> adj[N];
         for (int i = 0; i < M; i++) {
             int u = edges[i][0];
             int v = edges[i][1];
             int wt = edges[i][2];
             adj[u].push_back({v, wt});
         }
         
         vector<int> vis(N, 0);
         stack<int> st;
         for (int i = 0; i < N; i++) {
             if (!vis[i]) {
                 topoSort(i, vis, adj, st);
             }
         }
         
         vector<int> dist(N, 1e9);
         dist[0] = 0;
         while (!st.empty()) {
             int node = st.top();
             st.pop();
             
             for (auto it : adj[node]) {
                 int v = it.first;
                 int wt = it.second;
                 if (dist[node] + wt < dist[v]) {
                     dist[v] = dist[node] + wt;
                 }
             }
         }
         for (int i = 0; i < N; i++) {
             if (dist[i] == 1e9) dist[i] = -1;
         }
         
         return dist;
    }
};
// Link - https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        int e = edges.size();
        vector<vector<int>> result(V);
        for (int i = 0; i < e; i++) {
            result[edges[i].first].push_back(edges[i].second);
            result[edges[i].second].push_back(edges[i].first);
        }
        return result;
    }
};
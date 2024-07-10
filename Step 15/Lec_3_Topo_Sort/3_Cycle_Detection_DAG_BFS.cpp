// Link - https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// Directed Graph Cycle


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
	    vector<int> result;
	    
	    for (int i = 0; i < V; i++) {
	        for (auto it : adj[i]) {
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for (int i = 0; i < V; i++) {
	        if (indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    
	    while (!q.empty()) {
	        int node = q.front();
	        q.pop();
	        
	        result.push_back(node);
	        for (auto it : adj[node]) {
	            indegree[it]--;
	            if (indegree[it] == 0) q.push(it);
	        }
	    }
	    
	    if (result.size() == V) return false;
	    return true;
    }
};
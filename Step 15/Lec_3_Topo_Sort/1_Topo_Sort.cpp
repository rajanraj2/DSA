// Link - https://www.geeksforgeeks.org/problems/topological-sort/1
// Topological Sort


class Solution
{
    private:
    void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V, 0);
	    stack<int> st;
	    vector<int> result;
	    for (int i = 0; i < V; i++) {
	        if (!vis[i]) {
	            dfs(i, adj, vis, st);
	        }
	    }
	    while (!st.empty()) {
	        result.push_back(st.top());
	        st.pop();
	    }
	    return result;
	}
};
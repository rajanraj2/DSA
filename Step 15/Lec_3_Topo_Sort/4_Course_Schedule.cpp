// Link - https://leetcode.com/problems/course-schedule/
// Course Schedule


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> adj[V];
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
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

        if (result.size() == V) return true;
        return false;
    }
};
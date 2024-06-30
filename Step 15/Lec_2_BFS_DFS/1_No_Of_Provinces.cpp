// Link - https://leetcode.com/problems/number-of-provinces/
// Number of Provinces

// S.C. = O(N) + O(N)
// T.C. = O(N) + O(V+2E) 

class Solution {
public:
    void dfs(int m, int n, vector<int>& visited, vector<vector<int>>& isConnected) {
        visited[m] = 1;
        for (int i = 0; i < n; i++) {
            if (isConnected[m][i] == 1 && visited[i] == 0) {
                dfs(i, n, visited, isConnected);
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<int> visited(n,0);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                dfs(i, n, visited, isConnected);
                count++;
            }
        }
        return count;
    }
};
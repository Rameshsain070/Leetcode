class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& ans) {
        visited[node] = 1; 
        
        for (int neighbour : adj[node]) {
            if (visited[neighbour] == 0) {
                if (!dfs(neighbour, adj, visited, ans)) {
                    return false; 
                }
            } else if (visited[neighbour] == 1) {
                return false; 
            }
        }
        
        visited[node] = 2; 
        ans.push_back(node); 
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int E = prerequisites.size();
        vector<int> visited(numCourses, 0);
        vector<vector<int>> adj(numCourses); 
        vector<int> ans;

        for (int i = 0; i < E; i++) {
            int U = prerequisites[i][0];
            int V = prerequisites[i][1];
            adj[V].push_back(U); 
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(i, adj, visited, ans)) {
                    return {}; 
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
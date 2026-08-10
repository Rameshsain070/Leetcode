class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for (int i=0 ; i<arr.size() ; i++){
            adj[arr[i][0]].push_back(arr[i][1]);
            indegree[arr[i][1]]++;
        }
        queue<int> q;
        for (int i=0  ; i<n ; i++){
            if (indegree[i]==0) q.push(i);
        }

        int cnt=0;

        while (!q.empty()){
            int x=q.front();
            q.pop();
            cnt++;
            for (int i=0 ; i<adj[x].size() ; i++){
                indegree[adj[x][i]]--;
                if (indegree[adj[x][i]]==0){
                    q.push(adj[x][i]);
                }
            }
        }
        
        return cnt==n;
    }
};
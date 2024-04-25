class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int>& informTime, int curr,int &ans){
        int x = adj[node].size();
        if(x > 0){
            curr += informTime[node];
            ans = max(ans, curr);
            for(int i=0;i<x;i++){
                dfs(adj[node][i],adj,informTime,curr,ans);
            }
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            int j = manager[i];
            if(j != -1)
                adj[j].push_back(i);
        }

        dfs(headID,adj,informTime,0,ans);

        return ans;
    }
};
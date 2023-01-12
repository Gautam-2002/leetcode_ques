class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans;
    vector<int> dfs(string &s,int curr,int parent){
        vector<int> cnt(26,0);
        for(auto x:adj[curr]){
            if(x!=parent){
                auto temp = dfs(s,x,curr);
                for(int i=0;i<26;i++){
                    cnt[i]+=temp[i];
                }
            }
        }
        int ch = s[curr]-'a';
        cnt[ch]++;
        ans[curr] = cnt[ch];
        return cnt;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.resize(n);
        ans.resize(n,1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(labels,0,-1);
        return ans;
    }
};
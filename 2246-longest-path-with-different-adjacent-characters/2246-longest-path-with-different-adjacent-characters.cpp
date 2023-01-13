class Solution {
public:
    int ans = 1;
    vector<vector<int>> adj;
    int dfs(int node,int parent,string &s){
        //to strore the max length upto that node include it, so intialize with 1
        int maxpath=1;
        for(auto x : adj[node]){
            if(x!=parent){
                int temp = dfs(x,node,s);
                
                //if node char ans its child char is not equal
                if(s[node]!=s[x]){
                    //update the ans with maximum val
                    //update the maxpath length to return to its parent
                    ans = max(ans,maxpath+temp);
                    maxpath = max(maxpath,1+temp);
                }
            }
        }
        return maxpath;
    }
    int longestPath(vector<int>& parent, string s){
        int n = parent.size();
        adj.resize(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        dfs(0,-1,s);
        return ans;
    }
};
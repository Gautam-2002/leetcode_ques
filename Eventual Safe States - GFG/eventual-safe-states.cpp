//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool dfs(int node,vector<int> graph[],vector<int> &vis,vector<int> &path,vector<int> &check){
        vis[node]=1;
        path[node]=1;
        check[node]=0;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,vis,path,check)==true){
                    // check[node]=0;
                    return true;
                }
            }
            else if(path[it])
                return true;
        }
        check[node]=1;
        path[node]=0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int n, vector<int> graph[]) {
        // code here
        vector<int> vis(n,0);
        vector<int> path(n,0);
        vector<int> check(n,0);
        vector<int> safeNodes;
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(i,graph,vis,path,check);
        }
        for(int i=0;i<n;i++){
            if(check[i]==1)safeNodes.push_back(i);
        }
        return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
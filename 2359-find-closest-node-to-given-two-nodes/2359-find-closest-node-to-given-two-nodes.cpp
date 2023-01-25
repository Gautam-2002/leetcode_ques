class Solution {
public:
    void dfs(vector<int>& edges,int node,vector<int>&dis,vector<int> &vis,int dist){
        if(node == -1 || vis[node] == 1)return;
        
        vis[node] = 1;
        dis[node] = dist;
        dfs(edges,edges[node],dis,vis,dist+1);
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis1(n,-1);
        vector<int> dis2(n,-1);
        vector<int> vis1(n,0);
        vector<int> vis2(n,0);
        
        dfs(edges,node1,dis1,vis1,0);
        
        dfs(edges,node2,dis2,vis2,0);
        
        int ans = -1;
        int val = n;
        
        for(int i=0;i<n;i++){
            if(dis1[i] != -1 && dis2[i] != -1){
                if(max(dis1[i],dis2[i])<val){
                    val = max(dis1[i],dis2[i]);
                    ans = i;
                }
            }
        }
        return ans;
    }
};
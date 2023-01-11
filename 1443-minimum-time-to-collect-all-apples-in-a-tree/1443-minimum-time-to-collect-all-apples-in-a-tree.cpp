class Solution {
public:
    vector<vector<int>> adjlist;
    int dfs(vector<bool>& hasApple,int curr,int parent,int dis){
        int dfc = 0;
        int dfr = 0;
        for(auto x:adjlist[curr]){
            if(x!=parent){
                dfr = dfs(hasApple,x,curr,dis+1);
                
                if(dfr!=0)
                    dfc += dfr-dis;
            }
        }
        
        return (dfc || hasApple[curr]) ? dfc+dis : 0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adjlist.resize(n);
        for(auto x:edges){
            adjlist[x[0]].push_back(x[1]);
            adjlist[x[1]].push_back(x[0]);
        }
        return dfs(hasApple,0,-1,0)*2;
    }
};
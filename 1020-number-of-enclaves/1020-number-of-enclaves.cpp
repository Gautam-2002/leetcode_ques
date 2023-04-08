class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i==0 || j==0 || i==n-1 ||j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr<n && nr>=0 && nc<m && nc>=0 && 
                    vis[nr][nc]==0 && grid[nr][nc]==1){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( vis[i][j]==0 && grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};
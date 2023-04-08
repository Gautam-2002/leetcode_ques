class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        int cnt1 = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1)cnt1++;
            }
        }
        int tm = 0;
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        int cnt2=0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm,t);
            for(int i = 0;i<4;i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr >=0 && nr<n && nc>=0 && nc<m &&
                   vis[nr][nc]!=2 && grid[nr][nc]==1){
                    q.push({{nr,nc},t+1});
                    vis[nr][nc]=2;
                    cnt2++;
                }
            }
        }
        if(cnt1!=cnt2)return -1;
        
        return tm;        
    }
};
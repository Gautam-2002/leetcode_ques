class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid){
        vis[row][col]=1;
        int n = grid.size();int m = grid[0].size();
        int nr,nc;
        nr=row-1;nc=col;
        if(nr>=0 && nr <n && nc>=0&& nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
            dfs(nr,nc,vis,grid);
        }nr=row+1;nc=col;
        if(nr>=0 && nr <n && nc>=0&& nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
            dfs(nr,nc,vis,grid);
        }nr=row;nc=col-1;
        if(nr>=0 && nr <n && nc>=0&& nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
            dfs(nr,nc,vis,grid);
        }nr=row;nc=col+1;
        if(nr>=0 && nr <n && nc>=0&& nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
            dfs(nr,nc,vis,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();//rows
        int m = grid[0].size();//cols
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};
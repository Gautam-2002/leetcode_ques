class Solution {
public:
    vector<int> dr={-1,0,1,0};
    vector<int> dc={0,1,0,-1};
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&mat){
        vis[row][col]=1;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<4;i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if( nr < n && nc < m && nr>=0 && nc>=0
                && vis[nr][nc]!=1 && mat[nr][nc]=='O'){
                dfs(nr,nc,vis,mat);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(vis[0][i]==0 && board[0][i]=='O'){
                dfs(0,i,vis,board);
            }
            if(vis[n-1][i]==0 && board[n-1][i]=='O'){
                dfs(n-1,i,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(vis[i][m-1]==0 && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
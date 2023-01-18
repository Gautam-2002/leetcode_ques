class Solution {
public:
    void dfs(int r, int c,vector<vector<int>> &ans,vector<vector<int>>& image,
      int newColor,int dr[],int dc[],int oldColor,int n,int m){
        
        ans[r][c]=newColor;
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && 
               image[nr][nc]==oldColor && ans[nr][nc] != newColor){
                dfs(nr,nc,ans,image,newColor,dr,dc,oldColor,n,m);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        dfs(sr,sc,ans,image,newColor,delrow,delcol,oldColor,n,m);
        return ans;
    }
};
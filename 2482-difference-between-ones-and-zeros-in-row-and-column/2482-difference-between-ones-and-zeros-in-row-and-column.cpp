class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0;i<n;i++){
            int o = 0,z=0;
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1)
                    o++;
                else
                    z++;
            }
            row[i]+=(o-z);            
        }
        for(int i=0;i<m;i++){
            int o = 0,z=0;
            for(int j = 0;j<n;j++){
                if(grid[j][i]==1)
                    o++;
                else
                    z++;
            }
            col[i]+=(o-z);            
        }
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                ans[i][j] = row[i]+col[j];
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(m*n != r*c)return mat;
        if(m==r && n==c)return mat;
        vector<int> temp(m*n);
        int idx = 0;
        for(int i = 0;i<m;i++){
            for(int j= 0;j<n;j++)
                temp[idx++]=(mat[i][j]);
        }
        idx=0;
        vector<vector<int>>ans(r,vector<int>(c,0));
        for(int i =0;i<r;i++){
            for(int j=0;j<c;j++)
                ans[i][j]=temp[idx++];
        }
        return ans;        
    }
};
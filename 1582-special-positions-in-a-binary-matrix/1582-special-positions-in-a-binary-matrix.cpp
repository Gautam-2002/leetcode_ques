class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int x = 0;int idx = -1;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    x++;
                    idx = j;
                }
            }
            if(x==1){
                for(int k = 0;k<n;k++){
                    if(mat[k][idx]==1 & k!=i){
                        x = -1;
                        break;
                    }
                }
                if(x!=-1)
                    ans++;
            }
        }
        return ans;
    }
};
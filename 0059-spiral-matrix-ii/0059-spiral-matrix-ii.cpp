class Solution {
public:
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int x = 1;
        int r = n;
        int c = r;
        int rs = 0,cs = 0,re = r-1,ce = c-1;
        while(x <= n*n){
            for(int i = cs;i <= ce && x<=n*n;i++){
                matrix[rs][i] = x++;
            }
            rs++;
            for(int i = rs;i <= re && x<=n*n;i++){
                matrix[i][ce] = x++;
            }
            ce--;
            for(int i = ce;i >= cs && x<=n*n;i--){
                matrix[re][i] = x++;
            }
            re--;
            for(int i = re;i >= rs && x<=n*n;i--){
                matrix[i][cs] = x++;
            }
            cs++;
        }
        
        return matrix;
    }
};
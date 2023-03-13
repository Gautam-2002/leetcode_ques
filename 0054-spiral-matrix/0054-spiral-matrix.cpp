class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int r = matrix.size();
        int c = matrix[0].size();
        int n = r*c;
        int rs = 0,cs = 0,re = r-1,ce = c-1;
        while(n > 0){
            for(int i = cs;i <= ce && n > 0;i++){
                ans.push_back(matrix[rs][i]);
                n--;
            }
            rs++;
            for(int i = rs;i <= re && n > 0;i++){
                ans.push_back(matrix[i][ce]);
                n--;
            }
            ce--;
            for(int i = ce;i >= cs && n > 0;i--){
                ans.push_back(matrix[re][i]);
                n--;
            }
            re--;
            for(int i = re;i >= rs && n > 0;i--){
                ans.push_back(matrix[i][cs]);
                n--;
            }
            cs++;
        }
        return ans;
    }
};
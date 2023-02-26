class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int x = mat.size();
        for(int i = 0;i<x;i++){
            sum+=mat[i][i];
        }
        int it = 0;
        for(int i = x-1;i>=0;i--){
            sum+=mat[it++][i];
        }
        if(x%2==1){
            
            sum -= mat[x/2][x/2];
        }
        return sum;
    }
};
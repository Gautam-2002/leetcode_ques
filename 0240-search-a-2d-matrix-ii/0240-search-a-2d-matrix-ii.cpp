class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int ri = 0;
        int ci = c-1;
        
        while(ri<r && ci>=0){
            int element = matrix[ri][ci];
            
            if(element==target){
                return true;
            }
            else if(element<target){
                ri++;
            }
            else{
                ci--;
            }
        }
        return false;
    }
};
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        for(int i = 0;i<grid[0].size();i++){
            int curr = i;
            for(int j = 0;j<grid.size();j++){
                int next = curr + grid[j][curr];
                if(next < 0 || next >= grid[0].size() || grid[j][curr]!=grid[j][next]){
                    ans[i] = -1;
                    break;
                }
                ans[i]=next;
                curr = next;
            }
        }
        return ans;
    }
};
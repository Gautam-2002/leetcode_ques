class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> row;
        unordered_map<string,int> col;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            string r = "";
            string c = "";
            for(int j=0;j<m;j++){
                r += to_string(grid[i][j]);
                c += to_string(grid[j][i]);
                r+="-";
                c+="-";
            }
            row[r]++;
            col[c]++;
        }
        int ans = 0;
        for(auto it:row){
            if(col.find(it.first) != col.end()){
                ans += it.second*col[it.first];
            }
        }
        return ans;
    }
};
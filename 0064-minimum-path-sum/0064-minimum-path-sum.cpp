class Solution {
public:
    int unique_td(int i, int j, vector<vector<int>>& td, vector<vector<int>>& grid)
    {
        if (i == 0 && j == 0) return grid[0][0];
        if (i < 0 || j < 0) return INT_MAX;
        if (td[i][j] != -1) return td[i][j];
        td[i][j] = grid[i][j] + min(unique_td(i-1, j, td, grid), unique_td(i, j-1, td, grid));
        return td[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> td(m, vector<int>(n, -1));
        return unique_td(m-1, n-1, td, grid);
    }
};
typedef pair<int,pair<int,int>> ppi;
// {0,+1} {+1,0} {0,-1} {-1,0}
int row[] = {0,1,0,-1};
int col[] = {1,0,-1,0};
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        int n = grid.size(), m = grid[0].size();

        priority_queue<ppi, vector<ppi>, greater<ppi> > pq;
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));

        pq.push({0,{0,0}});
        dis[0][0] = 0;

        while(pq.size() > 0){
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            for(int i = 0; i<4 ; i++){
                int xd = x + row[i];
                int yd = y + col[i];
                if(xd >= 0 && xd < n && yd >= 0 && yd < m){
                    int curr = time;
                    int t = grid[xd][yd];
                    
                    int diff = t - curr;
                    if(diff > 0){
                        if(diff & 1)curr += diff;
                        else curr += (diff+1);
                    }
                    else curr++;
                    if(dis[xd][yd] > curr){
                        dis[xd][yd] = curr;
                        pq.push({curr,{xd,yd}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};
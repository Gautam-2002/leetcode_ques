class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        pair<int,int> ans = make_pair(INT_MAX,-1);
        int idx = 0;
        for(auto i:points){
            if((abs(i[0]-x)+abs(i[1]-y)) < ans.first && (x==i[0]||y==i[1])){
                ans.first = abs(i[0]-x)+abs(i[1]-y);
                ans.second = idx;
            }
            idx++;
        }
        return ans.second;
    }
};
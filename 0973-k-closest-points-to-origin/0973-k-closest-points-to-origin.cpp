#define ppi pair<int,pair<int,int>>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<ppi> pq;
        for(auto i: points){
            pq.push({i[0]*i[0]+i[1]*i[1],{i[0],i[1]}});
            if(pq.size()>k)
                pq.pop();
        }
        while(pq.size()>0){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};
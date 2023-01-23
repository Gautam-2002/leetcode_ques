class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.size()==0)return 1;
        unordered_map<int,pair<int,int>> mp;
        for(auto it:trust){
            mp[it[0]].first++;
            mp[it[0]].second+=0;
            mp[it[1]].first+=0;
            mp[it[1]].second++;
        }
        for(auto i:mp){
            if(i.second.first==0 && i.second.second==n-1){
                return i.first;
            }
        }
        return -1;
    }
};
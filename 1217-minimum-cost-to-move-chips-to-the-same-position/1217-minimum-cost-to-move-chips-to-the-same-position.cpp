class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        unordered_map<int,int> mp;
        
        for(auto i:position){
            mp[i]++;
        }

        int odd = 0,even = 0;
        for(auto i:mp){
            if(i.first%2==0)even+=i.second;
            else odd+=i.second;
        }
        return min(odd,even);
    }
};
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums)
            mp[i]++;
        int ans = -1;
        for(auto i:mp){
            if(i.first > 0 && mp.find(i.first*-1) != mp.end()){
                ans = max(ans,i.first);
            }
        }
        return ans;
    }
};
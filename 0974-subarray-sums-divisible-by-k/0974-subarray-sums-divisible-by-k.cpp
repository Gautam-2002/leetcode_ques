class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = 0;
        int prefix = 0;
        mp[0]++;
        for(int i=0; i<n; i++){
            prefix+=nums[i];
            int mod = ((prefix % k) + k)% k;
            if(mp.find(mod)!=mp.end()){
                ans+=mp[mod];
            }
            mp[mod]++;
        }
        return ans;
    }
};
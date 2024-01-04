class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        int ans = 0;
        for (auto [_, c]: mp) {
            if (c == 1) {
                return -1;
            }
            ans += ceil((double)(c) / 3);
        }
        return ans;
    }
};
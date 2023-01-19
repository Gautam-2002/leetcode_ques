class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> prefix(n);
        prefix[0] = nums[0]>0?nums[0]:(nums[0]*(-1)*k)+nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+nums[i];
            if(prefix[i]<0){
                prefix[i]%=k;
                prefix[i]+=k;
            }
        }
        for(int i=0;i<n;i++){
            //frequency of same remainders
            mp[prefix[i]%k]++;
        }
        mp[0]++;
        int ans = 0;
        for(auto it:mp){
            // using combination formula on same remainders
            ans += (it.second * (it.second-1))/2;
        }
        return ans;
    }
};
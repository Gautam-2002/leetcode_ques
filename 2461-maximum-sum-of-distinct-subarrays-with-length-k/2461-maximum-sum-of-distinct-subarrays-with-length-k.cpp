class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long curr = 0;
        int n = nums.size();
        // for(int i=0;i<n;i++){
        //     unordered_map<int,int> mp;
        //     int j = i+k;
        //     int l = i;
        //     while(l < j && j <= n){
        //         mp[nums[l]]++;
        //         if(mp[nums[l]]>1){
        //             curr=0;
        //             break;
        //         }
        //         curr += nums[l];
        //         l++;
        //     }
        //     // cout<<curr<<endl;
        //     ans = max(ans,curr);
        //     curr = 0;
        // }
        // return ans;
        unordered_map<int,int> mp;
        int i=0,j=0;
        while(i+k <= n){
            while(j-i<k){
                mp[nums[j]]++;
                curr += nums[j++];
            }
            // cout<<curr<<" * "<<i<<" "<<j<<endl;
            if(mp.size()==k){
                ans = max(ans,curr);
            }
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            curr -= nums[i];
            i++;
        }
        return ans;
    }
};
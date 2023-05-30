class Solution {
public:
    int subarraySum(vector<int>& nums, int k,int n) {
        vector<int>pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1] = nums[i]+pre[i];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j = i;j<n;j++){
                if(pre[j+1]-pre[i]==k)
                    ans++;
            }
        }
        return ans;
    }
    int subarraySum1(vector<int>& nums, int k,int n) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(n,0);
        
        for(int i=0;i<n;i++){
            arr[i] = nums[i]&1?1:0;
        }
        
        int ans = subarraySum1(arr,k,n);        
        return ans;
    }
};
class Solution {
public:
    // subarray sum equals k -- O(n*n) -- using prefix sum
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
    // subarray sum equals k -- O(n) -- using map
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
    // math - o(n)--time & o(1)--space
    int solve(vector<int>& nums, int k){
        int cnt = 0;
        vector<int> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                v.push_back(cnt);
                cnt=0;
            }
            else
                cnt++;
        }
        v.push_back(cnt);
        if(v.size()-1<k){
            return 0;
        }
        // 2,2,2,1,2,2,1,2,2,2
        // 3,2,3
        int ans = 0;
        int l=0,r = k;
        while(r<v.size()){
            ans += (v[l]+1)*(v[r]+1);
            l++;
            r++;
        }
        return ans;
        
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> arr(n,0);
        
//         for(int i=0;i<n;i++){
//             arr[i] = nums[i]&1?1:0;
//         }
//         int ans = subarraySum1(arr,k,n);
        int ans = solve(nums,k);
        return ans;
    }
};
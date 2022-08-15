class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int currsum=0;
        for(int i=0;i<n;i++){
            ans[i]+=currsum+nums[i];
            currsum+=nums[i];
        }
        return ans;        
    }
};
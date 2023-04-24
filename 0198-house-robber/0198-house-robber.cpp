class Solution {
public:
    int solve(vector<int>& nums,int n,vector<int> &dp){
        if(n>=nums.size())
            return 0;
        
        if(dp[n]!=-1)return dp[n];
        
        int in = nums[n] + solve(nums,n+2,dp);
        int ex = solve(nums,n+1,dp);
        
        return dp[n]=max(in,ex);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
};
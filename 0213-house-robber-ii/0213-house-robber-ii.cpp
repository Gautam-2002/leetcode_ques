class Solution {
public:
    
    int solve(vector<int>& nums,int i,vector<int> &dp){
        if(i>=nums.size())return 0;
        if(dp[i] != -1)return dp[i];
        
        int in = nums[i]+solve(nums,i+2,dp);
        int ex = solve(nums,i+1,dp);
        
        return dp[i] = max(in,ex);
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        
        vector<int> t1(nums.begin()+1,nums.end());
        vector<int> t2(nums.begin(),nums.end()-1);
        
        vector<int>dp1(nums.size(),-1);
        int a = solve(t1,0,dp1);
        
        vector<int>dp2(nums.size(),-1);
        int b = solve(t2,0,dp2);
        
        return max(a,b);
    }
};
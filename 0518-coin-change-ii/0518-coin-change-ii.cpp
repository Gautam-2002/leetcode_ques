class Solution {
public:
    int solve(int val,int n,vector<int> &arr,int idx,vector<vector<int>> &dp){
        if(val==0)return 1;
        if(idx>=n){
            return 0;
        }
        if(dp[idx][val] != -1){
            return dp[idx][val];
        }
        int ans = 0;
        for(int i=idx;i<n;i++){
            if(val-arr[i]>=0)
                ans+=solve(val-arr[i],n,arr,i,dp);
        }
        return dp[idx][val] = ans;    
    }
    int change(int amount, vector<int>& coins) {
        int n  = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return solve(amount,n,coins,0,dp);
    }
};
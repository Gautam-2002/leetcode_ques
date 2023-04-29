class Solution {
public:
    int solve(int val,vector<int> &arr,int n,vector<vector<int>> & dp){
        if(val==0)return 0;
        if(n<0)return INT_MAX;
        
        if(dp[n][val]!=-1){
            return dp[n][val];
        }
        
        int x=INT_MAX,y=INT_MAX;
        
        if(val>=arr[n]){
            x = solve(val-arr[n],arr,n,dp);
            if(x!=INT_MAX)
                x+=1;
        }
        
        y = solve(val,arr,n-1,dp);
        
        return dp[n][val] = min(x,y);
        
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n  = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans = solve(amount,coins,n-1,dp);
        if(ans == INT_MAX)return -1;
        return ans;
    }
};
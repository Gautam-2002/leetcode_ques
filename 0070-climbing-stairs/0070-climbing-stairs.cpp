class Solution {
public:
    int memo(int n,vector<int>&dp)
    {
        if (n == 0 || n == 1)
            return 1;
        if(dp[n]!=-1)return dp[n];
        int l = memo(n - 1,dp);
        int r = memo(n - 2,dp);
        // cout << "n :" << n << " l: " << l << " r: " << r << endl;
        return dp[n] = l + r;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return memo(n,dp);
    }
};
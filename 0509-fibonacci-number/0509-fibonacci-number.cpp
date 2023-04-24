class Solution {
public:
    int dp[31];
    
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        memset(dp,-1,sizeof(dp));
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        return dp[n] = fib(n-1) + fib(n-2);
    }
};
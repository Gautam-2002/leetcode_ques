class Solution {
    public int climbStairs(int n) {
        int []dp = new int[n+1];
        Arrays.fill(dp,-1);
        return climb(n,dp);
    }
    public int climb(int n,int dp[]){
        if(n==1 || n==0)
            return 1;
        if(dp[n]!=-1)return dp[n];
        int one = climb(n-1,dp);
        int two = climb(n-2,dp);
        dp[n] = one+two;
        return dp[n];
    }
    // public int climbStairs(int n) {
    //     int []ans = {0};
    //     int step = 0;
    //     climb(n,step,ans);
    //     return ans[0];
    // }
    // public void climb(int n,int step,int []ans){
    //     if(step >= n){
    //         if(step==n)ans[0]++;
    //         return;
    //     }
    //     climb(n,step+1,ans);
    //     if((n-step)>=2)
    //     climb(n,step+2,ans);
    // }
}
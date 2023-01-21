class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int []dp = new int[cost.length];
        Arrays.fill(dp,-1);
        int x = climb(cost,dp,0);
        int y = climb(cost,dp,1);
        return Math.min(x,y);
    }
    public int climb(int []cost,int []dp,int n){
        if(n>=cost.length){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int a = climb(cost,dp,n+1);
        int b = climb(cost,dp,n+2);
        dp[n] = Math.min(a,b)+cost[n];
        
        return dp[n];
    }
}
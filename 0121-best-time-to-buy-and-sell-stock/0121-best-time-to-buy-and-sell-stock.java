class Solution {
    public int maxProfit(int[] prices) {
        int ans=0;
        int mini=Integer.MAX_VALUE;
        for(int i=0;i<prices.length;i++){
            mini=Math.min(prices[i],mini);
            ans=Math.max(ans,prices[i]-mini);
        }
        return ans;
    }
}
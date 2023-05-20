class Solution {
    public int largestAltitude(int[] gain) {
        int []pre = new int[gain.length+1];
        int ans = 0;
        for(int i=0;i<gain.length;i++){
            pre[i+1] = gain[i] + pre[i];
            ans = Math.max(ans,pre[i+1]);
        }
        return ans;        
    }
}
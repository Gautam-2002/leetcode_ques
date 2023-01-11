class Solution {
    public int[] runningSum(int[] nums) {
        int []ans = new int[nums.length];
        int curr=0;
        for(int i=0;i<nums.length;i++){
            curr+=nums[i];
            ans[i]=curr;
        }
        return ans;
    }
}
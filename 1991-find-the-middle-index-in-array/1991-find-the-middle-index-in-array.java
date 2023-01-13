class Solution {
    public int findMiddleIndex(int[] nums) {
        int total = 0;
        int n = nums.length;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        int leftsum=0;
        for(int i=0;i<n;i++){
            if(leftsum*2 == total-nums[i])
                return i;
            leftsum+=nums[i];
        }
        return -1;
    }
}
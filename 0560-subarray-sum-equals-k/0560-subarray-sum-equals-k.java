class Solution {
    public int subarraySum(int[] nums, int k) {
        int pre[] = new int[nums.length+1];
        for(int i=0;i<nums.length;i++){
            pre[i+1] = nums[i]+pre[i];
        }
        int ans = 0;
        for(int i=0;i<nums.length;i++){
            for(int j = i;j<nums.length;j++){
                if(pre[j+1]-pre[i]==k)
                    ans++;
            }
        }
        return ans;
    }
}
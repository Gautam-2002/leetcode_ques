class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] >= nums[i+1]){
                // counting no. of operation require to make nums[i] and nums[i+1] stricly increasing
                ans += nums[i]-nums[i+1]+1;
                // incrementing value
                nums[i+1] = nums[i]+1;
            }
        }
        return ans;
    }
};
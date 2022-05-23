class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //brute force
        vector<int> ans(2,-1);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    ans[0]=i;
                    ans[1]=j;
                    i=nums.size()+1;
                    break;
                }
            }
        }
        return ans;
    }
};
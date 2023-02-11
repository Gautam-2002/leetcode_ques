class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int total = 0;
        for(int i = 0;i<nums.size();i++){
            total+=nums[i];
        }
        int sum = 0;
        vector<int> ans;
        for(int i = nums.size()-1;i>=0;i--){
            if(sum <= (total-sum)){
                sum+=nums[i];
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
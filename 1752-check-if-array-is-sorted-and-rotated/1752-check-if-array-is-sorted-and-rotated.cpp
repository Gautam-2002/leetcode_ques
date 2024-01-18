class Solution {
public:
    bool check(vector<int>& nums) {
        bool f = 0;
        int idx;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                if(nums[i]>nums[0])return false;
                f=1;
                idx=i;
                break;
            }
        }
        if(f){
            for(int i = idx+1;i<nums.size();i++){
                if(nums[0]<nums[i] || nums[i]<nums[i-1])return false;
            }
        }
        return true;
    }
};
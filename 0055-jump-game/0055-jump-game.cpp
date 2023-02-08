class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==0 && i<nums.size()-1 && m<=i)
                return false;
            m = max(m,i+nums[i]);
        }
        if(m<nums.size()-1)return false;
        return true;
    }
};
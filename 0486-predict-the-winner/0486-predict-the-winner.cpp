class Solution {
public:
    int solve(vector<int>&nums,int s,int e){
        if(s>e)return 0;
        if(s==e)return nums[s];//or nums[e];
        
        int op1 = nums[s] + min(solve(nums,s+2,e),solve(nums,s+1,e-1));
        int op2 = nums[e] + min(solve(nums,s+1,e-1),solve(nums,s,e-2));
        
        return max(op1,op2);
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        int p1 = solve(nums,0,nums.size()-1);
        int total = 0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(p1 >= (total-p1))
            return true;
        return false;
    }
};
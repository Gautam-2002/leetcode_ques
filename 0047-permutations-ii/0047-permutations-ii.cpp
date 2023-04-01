class Solution {
public:
    void solve(vector<int>& nums,set<vector<int>>& ans,int idx){
        if(idx >= nums.size()){
            ans.insert(nums);
            return;
        }
        for(int i = idx;i < nums.size();i++){
            swap(nums[i],nums[idx]);
            solve(nums,ans,idx+1);
            // backtrack
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        solve(nums,ans,0);
        vector<vector<int>> res;
        for(auto i:ans){
            res.push_back(i);
        }
        return res;
    }
};
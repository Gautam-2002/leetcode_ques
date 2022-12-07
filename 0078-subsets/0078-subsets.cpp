class Solution {
public:
    void solve(vector<int>& nums,int i, vector<int>& p,vector<vector<int>> &ans){
        if(i>=nums.size()){
            ans.push_back(p);
            return;
        }
        p.push_back(nums[i]);
        solve(nums,i+1,p,ans);
        p.pop_back();
        solve(nums,i+1,p,ans);      
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> p;
        solve(nums,0,p,ans);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};
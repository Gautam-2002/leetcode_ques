class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums,int x,vector<int> &v,int i,int last){
        if(i==nums.size()){
            // for(int i: v)cout<<i<<"*";
            // cout<<endl;
            if(x==0){
                ans.push_back(v);
            }
            return;
        }
        
        if(x-nums[i] >= 0){
            if(i>0 && nums[i] == nums[i-1]){
                if(i == last){
                    v.push_back(nums[i]);
                    last = i;
                    solve(nums,x-nums[i],v,i+1,last+1);
                    v.pop_back();
                }
            }
            else{
                v.push_back(nums[i]);
                last = i;
                solve(nums,x-nums[i],v,i+1,last+1);
                v.pop_back();
            }
        }
        solve(nums,x,v,i+1,last);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,v,0,0);
        // vector<vector<int>> res(ans.begin(),ans.end());
        
        return ans;
    }
};
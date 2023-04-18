class Solution {
public:
    void solve(vector<int>& arr, int x,vector<int> v,vector<vector<int>> &ans,int i){
        if(i>=arr.size() || x<=0){
            if(x==0){
                ans.push_back(v);
            }
            return;
        }
        
        if(x-arr[i]>=0){
        v.push_back(arr[i]);
        solve(arr,x-arr[i],v,ans,i);
        v.pop_back();
        }
        solve(arr,x,v,ans,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        solve(candidates,target,v,ans,0);
        return ans;
    }
};
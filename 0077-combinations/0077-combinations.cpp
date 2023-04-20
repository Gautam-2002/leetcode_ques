class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n,int k,vector<int> &v,int i){
        if(i>n || k<=0){
            if(k==0)
                ans.push_back(v);
            return;
        }
        solve(n,k,v,i+1);
        v.push_back(i);
        solve(n,k-1,v,i+1);
        v.pop_back();
        // if(v.size() == k){
        //     ans.push_back(v);
        //     return;
        // }        
        // for(int j=i;j<n+1;++){
        //     v.push_back(j);
        //     solve(n,k,v,j+1);
        //     v.pop_back();
        // }
     }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        solve(n,k,v,1);
        return ans;
    }
};
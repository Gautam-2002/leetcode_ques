class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0,s,path,ans);
        return ans;
    }
    void solve(int idx,string s,vector<string>path,vector<vector<string>>&ans){
        if(idx == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=idx;i<s.size();++i){
            if(isPal(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    bool isPal(string s,int l,int r){
        while(l<=r){
            if(s[l++]!=s[r--]){
                return false;
            }
        }
        return true;
    }
};
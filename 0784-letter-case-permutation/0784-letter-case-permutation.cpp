class Solution {
public:
    void solve(string s,vector<string> &v,int i,string x){
        if(i==s.size()){
            v.push_back(x);
            return;
        }
        
        solve(s,v,i+1,x+s[i]);
        if(s[i]>='a'&&s[i]<='z')
            solve(s,v,i+1,x+char(s[i]-32));
        if(s[i]>='A'&&s[i]<='Z')
            solve(s,v,i+1,x+char(s[i]+32));   
        
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s,ans,0,"");
        return ans;
    }
};
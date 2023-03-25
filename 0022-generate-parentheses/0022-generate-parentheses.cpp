class Solution {
public:
    void solve(string s,int n,int o,int c,vector<string>&v){
        if(o+c==2*n){
            v.push_back(s);
            return;
        }
        if(o<n)
            solve(s+'(',n,o+1,c,v);
        if(c<o)
            solve(s+')',n,o,c+1,v);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve("",n,0,0,ans);
        return ans;
    }
};
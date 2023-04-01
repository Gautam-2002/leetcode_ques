class Solution {
public:
    void solve(string s,vector<string>& ans,string kp[],string x,int idx){
        if(idx >= s.size()){
            ans.push_back(x);
            return;
        }
        int num = s[idx]-'0';
        
        for(int i=0;i<kp[num].size();i++){
            x.push_back(kp[num][i]);
            solve(s,ans,kp,x,idx+1);
            x.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0)return ans;
        string keypad[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,ans,keypad,"",0);
        return ans;
    }
};
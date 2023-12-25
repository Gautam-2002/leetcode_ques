class Solution {
public:
    int memo[100] = {};
    int solve(string s, int idx){
        int n = s.size();
        if(idx == n)return 1;
        
        if(memo[idx] != 0)return memo[idx];
        
        if(s[idx] == '0') return 0;
        int ans = solve(s, idx+1);
        if(idx < n-1 && (s[idx]=='1' || (s[idx] == '2' && s[idx+1] < '7')))
            ans += solve(s, idx+2);
        return memo[idx] = ans;
    }
    int numDecodings(string s) {
        if(s.size() == 0)return 0;
        else{
            return solve(s,0);
        }
    }
};
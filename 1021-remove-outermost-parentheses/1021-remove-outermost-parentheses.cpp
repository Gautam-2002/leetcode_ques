class Solution {
public:
    string removeOuterParentheses(string s) {
//         https://leetcode.com/problems/remove-outermost-parentheses/discuss/815947/c%2B%2B-two-solution-stack-and-with-out-stack(only-slight-modification-in-stack-sol.)
        string ans = "";
        int st = 0;
        for( auto i:s){
            if(i == '('){
                if(st > 0){
                    ans+="(";
                }
                st++;
            }
            else{
                if(st>1){
                    ans+=")";
                }
                st--;
            }
        }
        return ans;        
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1;i<strs.size();i++){
            if(ans.size()>strs[i].size())
                ans = ans.substr(0,strs[i].size());
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]!=ans[j]){
                    ans = ans.substr(0,j);
                    break;
                }
            }
        }
        return ans;
    }
};
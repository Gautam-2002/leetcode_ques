class Solution {
public:
    vector<int> diStringMatch(string s) {
        int l = 0,r = s.size();
        vector<int> ans;
        for(int i = 0;i < s.size(); i++){
            if(s[i]=='I'){
                ans.push_back(l);
                l++;
            }
            else{
                ans.push_back(r);
                r--;
            }
        }
        if(s[s.size()-1]=='I')ans.push_back(r);
        else ans.push_back(l);
        return ans;
    }
};
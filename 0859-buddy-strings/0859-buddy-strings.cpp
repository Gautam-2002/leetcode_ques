class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size() )return false;
        if(s.size()==1)return false;
        int p =-1;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                if(p==-1){
                    p=i;
                }
                else if(p==-2){
                    return false;
                }
                else{
                    if(s[p]!=goal[i] || s[i]!=goal[p])return false;
                    p=-2;
                }
            }
        }
        if(p==-1){
            unordered_map<char,int>mp;
            for(auto i:s){
                mp[i]++;
            }
            for(auto i:mp){
                if(i.second>=2)
                    return true;
            }
            return false;
        }
        if(p>0)return false;
        return true;
    }
};
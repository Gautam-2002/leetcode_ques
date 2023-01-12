class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,bool> used;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i])
                    return false;
                else
                    continue;
            }
            else{
                if(used[t[i]]==true)
                    return false;
                mp[s[i]]=t[i];
                used[t[i]]=true;
            }
        }

        return true;
    }
};
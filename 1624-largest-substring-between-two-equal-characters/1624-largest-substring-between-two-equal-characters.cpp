class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                int x = i-mp[s[i]]-1;
                ans = max(ans,x);
            }
            else{
                mp[s[i]]=i;
            }
        }
        return ans;
    }
};
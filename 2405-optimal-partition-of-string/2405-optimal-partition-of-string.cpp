class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        unordered_map<char,int>mp;
        int last=0;
        int i=0;
        for(;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                ans++;
                last=i-1;
                mp.clear();
            }
            mp[s[i]]++;
        }
        if(last<i)ans++;
        return ans;
    }
};
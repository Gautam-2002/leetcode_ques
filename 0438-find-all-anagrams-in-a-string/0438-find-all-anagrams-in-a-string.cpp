class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> mp1(26,0);vector<int> mp2(26,0);
        if(s.size()<p.size()){return ans;}
        int window = p.size();
        int len = s.size();
        int l = 0,r=0;
        while(r<window){
            mp1[p[r]-'a']++;
            mp2[s[r]-'a']++;
            r++;
        }r--;
        while(r<len){
            if(mp1 == mp2)ans.push_back(l);
            r++;
            if(r!=len)mp2[s[r]-'a']++;
            mp2[s[l]-'a']--;
            l++;
        }
        return ans;
    }
};
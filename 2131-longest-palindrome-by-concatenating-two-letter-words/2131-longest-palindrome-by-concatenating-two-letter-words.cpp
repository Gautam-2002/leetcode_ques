class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto w:words){
            mp[w]++;
        }
        int ans = 0;
        vector<int> v;
        for(auto i:mp){
            string s = i.first;
            if(mp[s]!=-1){
                if(s[0]==s[1]){
                    v.push_back(i.second);
                    i.second=-1;
                }
                else{
                    string a = ""; a+= s[1]; a+=s[0];
                    if(mp.find(a)!=mp.end()){
                        int q = min(mp[s],mp[a]);
                        ans += q*4;
                        mp[s]=-1;
                        mp[a]=-1;
                    }
                }
            }
        }
        int m = 0;
        bool f = false;
        for(auto i:v){
            // cout<<i<<"*";
            if(i&1)f=true;
            if(i&1)m+=i-1;
            else m+=i;
        }
        if(f)m+=1;
        // cout<<m;
        ans+=(m*2);
        return ans;
    }
};
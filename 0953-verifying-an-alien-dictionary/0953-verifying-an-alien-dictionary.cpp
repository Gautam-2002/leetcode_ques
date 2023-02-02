class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        int idx = 0;
        for(auto x:order)
            mp[x]=idx++;
        for(int i = 0;i<words.size()-1;i++){
            string s = words[i];
            string t = words[i+1];
            int w = s.size()>t.size()?t.size():s.size();
            int j=0;
            for(;j<w;j++){
                if(mp[s[j]]<mp[t[j]]){ break;}
                if(mp[s[j]] > mp[t[j]]){
                    // cout<<s[j]<<" "<<t[j];
                    return false;
                }
            }
            if(j==w && s.size()>w)return false;
            // if(s[0]>t[0] || (s[0]<t[0] && s.size()>t.size()))
            //     return false;
        }
        return true;
    }
};
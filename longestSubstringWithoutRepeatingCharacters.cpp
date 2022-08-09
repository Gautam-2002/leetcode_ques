class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")return 0;
        unordered_map<char,int> mp;
        int count=0,maxcount=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]>0){
                i=mp[s[i]];
                count=0;
                mp.clear();
            }
            
            
            mp[s[i]]=i+1;
            count++;
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> mp;
        for(auto i:s){
            mp[i-'a']++;
        }
        int ans=0;
        for(auto it:mp){
            if(it.second%2==0){
                ans+=it.second;
            }
            else{
                ans+=it.second-1;
            }
        }
        if(ans<s.size()){
            ans++;
        }
        return ans;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1)return s;
        
        int n=s.size();
        int ans = 1;
        int st = 0,en = 0;
        
        // if(n%2 != 0){
            for(int i=0;i<n-1;++i){
                int l = i,r = i;
                while(l>=0 && r<n){
                    if(s[l] == s[r]){
                        l--;r++;
                    }
                    else
                        break;
                }
                int len = r-l-1;
                if(len > ans){
                    ans = len;
                    st = l+1;
                    en = r-1;
                }
            }
        // }
        // else{
            for(int i=0;i<n-1;++i){
                int l = i,r = i+1;
                while(l>=0 && r<n){
                    if(s[l] == s[r]){
                        l--;r++;
                    }
                    else
                        break;
                }
                int len = r-l-1;
                if(len > ans){
                    ans = len;
                    st = l+1;
                    en = r-1;
                }
            }
        // }
        return s.substr(st,ans);
    }
};
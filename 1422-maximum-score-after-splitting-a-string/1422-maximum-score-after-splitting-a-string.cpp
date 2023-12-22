class Solution {
public:
    int maxScore(string s) {
        int ans = INT_MIN;
        for(int i=1;i<=s.size()-1;i++){
            int z = 0,o = 0;
            for(int j = 0;j<i;j++){
                if(s[j]=='0'){
                    z++;
                }
            }
            for(int j = i;j<s.size();j++){
                if(s[j]=='1'){
                    o++;
                }
            }
            // cout<<z<<" "<<o<<endl;
            int x = z+o;
            ans = max(ans,x);
        }
        return ans;
    }
};
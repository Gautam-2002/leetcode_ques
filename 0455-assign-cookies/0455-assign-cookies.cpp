class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j = 0;
        int ans = 0;
        for(auto i:g){
            for(;j<s.size();j++){
                if(s[j]>=i){
                    ans++;
                    j++;
                    break;
                }
            }
        }
        return ans;
    }
};
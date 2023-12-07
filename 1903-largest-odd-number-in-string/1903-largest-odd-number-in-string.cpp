class Solution {
public:
    string largestOddNumber(string num) {
        int idx = -1;
        for(int i = 0; i < num.size(); i++){
            int x = num[i]-'0';
            if(x&1)
                idx = i;
        }
        string ans = "";
        if(idx != -1){
            for(int i=0;i<=idx;i++){
                ans+=num[i];
            }
        }
        return ans;
    }
};
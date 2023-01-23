class Solution {
public:
    string getHint(string secret, string guess) {
        string ans = "";
        int bulls = 0;
        int cows = 0;
        vector<int>s(10,0),g(10,0);
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                s[secret[i]-'0']++;
                g[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            cows+=min(s[i],g[i]);
        }
        ans+=to_string(bulls);
        ans+="A";
        ans+=to_string(cows);
        ans+="B";
        return ans;
    }
};
class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int ans = 0,n=word.size();
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1] ){
                word[i]='0';
                ans++;
                // cout<<word<<endl;
            }
            else if(abs(word[i]-word[i-1])==1 ){
                word[i]='0';
                ans++;
                // cout<<word<<endl;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans=0;
        for(int i=0;i<sentences.size();i++){
            string s=sentences[i];
            int words=1;
            for(int j=0;j<s.length();j++){
                if(s[j]==' ')words++;
            }
            ans=max(ans,words);
        }
        return ans;
    }
};
class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowel = {'a','e','i','o','u'};
        int cnt=0,ans=0;
        for(int i=0; i < s.size();i++){
            if(i<k){
                if(vowel.count(s[i]))cnt++;
            }
            else{
                ans = max(cnt,ans);
                if(vowel.count(s[i-k]))
                    cnt--;
                if(vowel.count(s[i]))
                    cnt++;
            }
        }
        ans = max(cnt,ans);
        return ans;
    }
};
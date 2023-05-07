class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char,int> mp;
        mp['a']=1;mp['e']=1;mp['i']=1;mp['o']=1;mp['u']=1;
        mp['A']=1;mp['E']=1;mp['I']=1;mp['O']=1;mp['U']=1;
        int i=0,j=s.size()-1;
        while(i<j){
            while(i<j && mp.find(s[i])==mp.end())i++;
            while(j>0 && mp.find(s[j])==mp.end())j--;
            if(i<j)swap(s[i],s[j]);
            i++;j--;
        }
        return s;
    }
};
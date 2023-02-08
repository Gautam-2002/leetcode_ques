class Solution {
public:
    void reverse(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            swap(s[i++],s[j--]);
        }
    }
    string reverseWords(string s) {
        string ans = "";
        string curr = "";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                reverse(curr);
                ans+=curr;
                ans+=' ';
                curr="";
            }
            else
                curr+=s[i];
        }
        reverse(curr);
        ans+=curr;
        return ans;
    }
};
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0,j=needle.size()-1;
        while(j < haystack.size()){
            string x = haystack.substr(i,j-i+1);
            if(x==needle)
                return i;
            i++;j++;
        }
        return -1;
    }
};
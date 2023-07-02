class Solution {
public:
    string removeOccurrences(string s, string part) {
        // s.find(part) --- return index of part in s
        // s.erase(index of string,length of string) --- erases the left most present trageted string in whole string
        while(s.size()!=0 && s.find(part) < s.size()){
            s.erase(s.find(part),part.size());
        }
        return s;
    }
};
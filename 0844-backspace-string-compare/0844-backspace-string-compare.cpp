class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a = "";
        string b = "";
        for(auto i:s){
            if(i!='#'){
                a+=i;
            }
            else if(a.size()>0&&i=='#'){
                a.pop_back();
            }
        }
        for(auto i:t){
            if(i!='#'){
                b+=i;
            }
            else if(b.size()>0&&i=='#'){
                b.pop_back();
            }
        }
        return a==b;
    }
};